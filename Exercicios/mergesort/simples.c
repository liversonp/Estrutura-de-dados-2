#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = -1;
    while( n != 42){
        scanf("%d", &n);
        if(n != 42)
            printf("%d\n", n);
    }
    return 0;
}