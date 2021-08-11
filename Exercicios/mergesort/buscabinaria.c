#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, num, aux = -1, j, l=0, r;
    scanf("%d %d",&n, &m);
    int *v = (int *)malloc(n*sizeof(int));
    
    for(int i=0; i<n;++i){
        scanf("%d", &v[i]);
    }
    
    for(int i=0; i<m;++i){        
        scanf("%d", &num);
        l = 0;
        r = n-1;
        j = (l+r)/2;
        while(l <= r && num != v[j]){

            if(num > v[r]){
                j = r+1;
                break;
            }

            if(num < v[j]){
                r = j-1;
            }

            else{
                l = j+1;
            }

            j = (l+r)/2;
        }

        if(j <= r && v[j]< num && v[j+1] > num){
            printf("%d\n", j+1);
        }
        
        else{
            printf("%d\n", j);
        }
    }

    return 0;
}