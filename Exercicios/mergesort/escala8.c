#include <stdio.h>
#include <stdlib.h>

void intercala(int *v1, int *v2, int t1, int t2){
    int iv1=0, iv2=0, ivt=0, m;
    int *vt = (int *)malloc((t1+t2)*sizeof(int));
    v1 = (int *)realloc(v1,(t1+t2)*sizeof(int));
    while(iv1 < t1 || iv2 < t2){
        if(iv1 <t1 && v1[iv1] < v2[iv2]){
            vt[ivt++] = v1[iv1++];
        }
        else{
            vt[ivt++] = v2[iv2++];
        }
    }

    for(int i=0;i<(t1+t2);++i){
        //v1[i] = vt[i];
        printf("v[%d] = %d\n", i+1,vt[i]);
    }

    printf("\n");
    free(vt);
}

int main(){
    int n1, prova = 0, n2, litd=0;
    int v2[1000000];
    scanf("%d", &n1);
    int *v1 = (int *)malloc(n1*sizeof(int));

    for(int i=0;i<2;++i){
        if(prova == 0){
            for(int j=0;j<n1;++j){
                scanf("%d", &v1[j]);
            }
            prova = 1;
        }
        else{
            scanf("%d", &n2);
            for(int j=0;j<n2;++j){
                scanf("%d", &v2[j]);
            }
            litd=1;
        }
        if(v1 && v2 && n1 && n2){
            intercala(v1, v2, n1, n2);
            n1 = n1+n2;
        }
    }

    for(int i =0; i<n1;++i){
        printf("%d ", v1[n1]);
    }

    printf("\n");
    return 0;
}