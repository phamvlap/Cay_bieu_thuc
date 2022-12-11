#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "CStack.c"
#include "NStack.c"

void inOrder(Tree T){
    if(T!=NULL){
        inOrder(T->Left);
        printf("%c ", T->Key);
        inOrder(T->Right);  
    }
}
void postOrder(Tree T){
    if(T!=NULL){
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%c ", T->Key);
    }
}
int isOperator(char c){
    if( c=='+' || c=='-' || c=='*' || c=='/' || c=='%')
        return 1;
    return 0;
}
int isOperand(char c){
    if(c>='0' && c<='9')
        return 1;
    return 0;
}
int priority(char c){
    if(c=='+' || c=='-')
        return 1;
    else{
        if(c=='*' || c=='/' || c=='%')
            return 2;
        else
            return 0;
    }
}
Tree createNode(char c, NStack *pS){
    Tree T=(struct Node*)malloc(sizeof(struct Node));
    T->Key=c;
    T->Right=topN(*pS);
    popN(pS);
    T->Left=topN(*pS);
    popN(pS);
    pushN(T, pS);
    return T;
}
Tree createTree(char *post){
    NStack S;
    makenullNStack(&S);
    CStack P;
    makenullCStack(&P);
    for(int i=0;i<strlen(post);++i){
        char c = post[i];
        if(isOperand(c)){
            Tree T=(struct Node*)malloc(sizeof(struct Node));
            T->Key = c;
            T->Left = NULL;
            T->Right = NULL;
            pushN(T, &S);
        }
        else{
            if(c=='(')
                pushC(c, &P);
            else{
                if(c==')'){
                    while(!isEmptyCStack(P) && topC(P)!='('){
                        Tree T=createNode(topC(P), &S);
                        popC(&P);
                    }
                    popC(&P);
                }
                else{
                    if(isOperator(c)){
                        while(!isEmptyCStack(P) && (priority(topC(P)))>=priority(c)){
                            Tree T=createNode(topC(P), &S);
                            popC(&P);
                        }
                        pushC(c, &P);
                    }
                }
            }
        }
    }
    while(!isEmptyCStack(P)){
        Tree T=createNode(topC(P), &S);
        popC(&P);
    }
    return topN(S);
}
double caculateTree (Tree T){
    if(T!=NULL){
        if(T->Left==NULL && T->Right==NULL)
            return (double)(T->Key-'0');
        else{
            double a = caculateTree(T->Left);
            double b = caculateTree(T->Right);
            char c = T->Key;
            double temp;
            if(c=='+')
                temp=a+b;
            else 
                if(c=='-')
                    temp=a-b;
                else
                    if(c=='*')
                        temp=a*b;
                    else
                        if(c=='/')
                            temp=a/b;
                        else
                            if(c=='%')
                                temp=(int)a%(int)b;
            return temp;
        }
    }
}

Tree createTree1(char *post){
    NStack S;
    makenullNStack(&S);
    CStack P;
    makenullCStack(&P);
    for(int i=0;i<strlen(post);++i){
        char c = post[i];
        char s[100];
        s[0]='\0';
        if(isOperand(c)){
            int j=0;
            while(isOperand(c)){
                s[j]=c;
                s[++j]='\0';
                ++i;
                c=post[i];
            }
            --i;
            Tree T=(struct Node*)malloc(sizeof(struct Node));
            T->Key = s;
            T->Left = NULL;
            T->Right = NULL;
            pushN(T, &S);
        }
        else{
            if(c=='(')
                pushC(c, &P);
            else{
                if(c==')'){
                    while(!isEmptyCStack(P) && topC(P)!='('){
                        Tree T=createNode(topC(P), &S);
                        popC(&P);
                    }
                    popC(&P);
                }
                else{
                    if(isOperator(c)){
                        while(!isEmptyCStack(P) && (priority(topC(P)))>=priority(c)){
                            Tree T=createNode(topC(P), &S);
                            popC(&P);
                        }
                        pushC(c, &P);
                    }
                }
            }
        }
    }
    while(!isEmptyCStack(P)){
        Tree T=createNode(topC(P), &S);
        popC(&P);
    }
    return topN(S);
}
int main(){
    Tree T;
    char s[100];
    fflush(stdin);
    fgets(s, 100, stdin);
    s[strlen(s)-1]='\0';
    T=createTree(s);
    postOrder(T);
    printf("\nGia tri bieu thuc tren la: %.2lf", caculateTree(T));
    return 0;
}