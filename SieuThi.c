#include<stdio.h>

int main(){
    int n, q, t1, t2, t3;
    scanf("%d%d%d%d%d", &n, &q, &t1,&t2, &t3);
    int m=1;
    int t=t3+1;
    while(m<=q && t>t3){
        int arr[100];
        for( int i=0;i<m;i++){
            arr[i]=0;
        }
        Queue Q;
        makenullQueue(&Q);
        for( int i=1;i<=n;i++){
            enQueue(i*t2, &Q);
        }
        int tong=0;
        while(!emptyQueue(Q)){
            int g=0;
            for( int i=0;i<m;i++){
                if(!emptyQueue(Q)){
                int p=front(Q);
                deQueue(&Q);
                if(p>arr[i])
                    g=p+t1;
                else
                    g=arr[i]+t1;
                arr[i]=g;
                tong+=(g-p);
                }
            }
        }
        t=tong/n;
        printf("So quay: %d; Thoi gian cho trung binh: %.1f", m, (float)t);
        m++;
    }
    if(t<t3)
        printf("=> Sieu thi se mo %d quay", m-1);
    if(m>q)
        printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.",m-1,(float)t);
    return 0;
}