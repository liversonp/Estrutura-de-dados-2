#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void merge (Item *v, int l, int meio, int r){
    Item *vt = (Item*)malloc((r-l+1)*sizeof(Item));
    
    int i=l,j=meio+1,k=0;
    while(i<=meio && j<=r){
        if(lesseq(v[i], v[j])){
            vt[k++] = v[i++];
        }
        else{
            vt[k++] = v[j++];
        }
    }
    while(i <= meio)
        vt[k++] = v[i++];
    
    while(j <= r)
        vt[k++]= v[j++];

    k=0;

    for(i=l;i<=r;i++){
        v[i] = vt[k++];
    }

    free(vt);
}

void mergesort(Item *v, int l, int r){
    if(l >=r)
        return;

    int meio = (l+r)/2;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(){
    int n, l=0, r;
    scanf("%d", &n);
    Item *v = (int*)malloc(n*sizeof(Item));
    for(int i=0;i<n;++i){
        scanf("%d", &v[i]);
    }
    r = n-1;
    mergesort(v,l,r);

    for(int i=0;i<n;++i){
        if(i == n-1)
            printf("%d\n", v[i]);
        else
            printf("%d ", v[i]);
    }
    return 0;
}