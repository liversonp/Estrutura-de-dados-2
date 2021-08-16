#include <stdio.h>
#include <stdlib.h>


typedef struct Item{
    int n;
    int pf;
} Item;

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void merge (Item *v, int l, int meio, int r){
    Item *vt = (Item*)malloc((r-l+1)*sizeof(Item));
    
    int i=l,j=meio+1,k=0;
    while(i<=meio && j<=r){
        if(lesseq(v[i].n, v[j].n)){
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

int busca_binaria(Item *v, int l, int r, int num, int ant){
    int pos = (l+r)/2;
    int achei = -1;
    int sla;

    if(pos == ant){
        return -1;
    }

    if(v[pos].n == num){
        return pos;
    }

    else{
        if(v[pos].n < num){
            l = pos;
        }
        else{
            r = pos;
        }
        ant = pos;
        achei = busca_binaria(v, l, r, num, ant);
    }
    return achei;
}

int main(){
    int n, m, l=0, r, num, fim;
    scanf("%d %d", &n, &m);
    Item *v = (Item*)malloc(n*sizeof(Item));
    for(int i=0;i<n;++i){
        scanf("%d", &v[i].n);
        v[i].pf = i;

    }
    r = n-1;
    mergesort(v,l,r);

    for(int i=0;i<m;++i){
        scanf("%d", &num);
        fim = busca_binaria(v, l, r+1, num, -1);
        if (fim == -1)
            printf("-1\n");
        else
            printf("%d\n", v[fim].pf);
    }
    return 0;
}