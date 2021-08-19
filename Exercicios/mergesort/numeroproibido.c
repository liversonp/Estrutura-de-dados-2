#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) {Item t; t=A; A=B; B=t}
#define cmpexch(A,B) {if (less(A,B)) exch(A,B);}

int busca_binaria(Item *v, int l, int r, int num, int ant){
    int pos = (l+r)/2;
    int achei = -1;
    int sla;

    if(pos == ant){
        return -1;
    }

    if(v[pos] == num){
        return pos;
    }

    else{
        if(v[pos] < num){
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
    int n, l=0, r, num, ver;
    scanf("%d", &n);
    Item *v = (Item*)malloc(n*sizeof(Item));
    
    for(int i=0;i<n;++i){
        scanf("%d", &v[i]);
    }

    r = n-1;

    mergesort(v, l, r);

    while(scanf("%d", &num) != EOF){
        ver = 0;
        l = 0;
        r = n-1;
        ver = busca_binaria(v,l,r+1, num,-1);
        if(ver == -1){
            printf("nao\n");
        }
        else{
            printf("sim\n");
        }
    }

    return 0;
}