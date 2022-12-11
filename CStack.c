#include<stdio.h>

#define MaxLength 100
typedef char CDataType;
typedef struct {
    CDataType A[MaxLength];
    int Top_idx;
}CStack;

void makenullCStack(CStack *pS){
    (*pS).Top_idx=MaxLength;
}
int isEmptyCStack(CStack S){
    return S.Top_idx==MaxLength;
}
int isFullCStack(CStack S){
    return S.Top_idx==0;
}
CDataType topC(CStack S){
    if(!isEmptyCStack(S))
        return S.A[S.Top_idx];
}
void pushC(CDataType x, CStack *pS){
    if(!isFullCStack(*pS)){
        --pS->Top_idx;
        pS->A[pS->Top_idx]=x;
    }
}
void popC(CStack *pS){
    if(!isEmptyCStack(*pS))
        ++pS->Top_idx;
}