#include<stdio.h>

#define MaxLength 100
typedef char KeyType;
struct Node {
    KeyType Key;
    struct Node* Left;
    struct Node* Right;
};
typedef struct Node* Tree;
typedef struct Node* DataType;
typedef struct {
    DataType A[MaxLength];
    int Top_idx;
}NStack;

void makenullNStack(NStack *pS){
    (*pS).Top_idx=MaxLength;
}
int isEmptyNStack(NStack S){
    return S.Top_idx==MaxLength;
}
int isFullNStack(NStack S){
    return S.Top_idx==0;
}
DataType topN(NStack S){
    if(!isEmptyNStack(S))
        return S.A[S.Top_idx];
}
void pushN(DataType x, NStack *pS){
    if(!isFullNStack(*pS)){
        --pS->Top_idx;
        pS->A[pS->Top_idx]=x;
    }
}
void popN(NStack *pS){
    if(!isEmptyNStack(*pS))
        ++pS->Top_idx;
}