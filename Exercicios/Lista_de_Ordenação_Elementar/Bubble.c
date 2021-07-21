//Ordene os números lidos da entrada padrão utilizando o Algoritmo de Ordenação BOLHA.

/*Entrada: A entrada possui um único caso de teste com uma quantidade arbitrária de números, a entrada termina quando o arquivo terminar (EOF). Os números cabem em um inteiro de 3232bits.

Sabemos que cada caso de teste não possui mais que 1000 elementos.

Saida: Imprima os mesmos números ordenados de forma não decrescente. Os números devem ser separados por espaço e não deve sobrar espaço após o último número que deve ter uma quebra de linha.
*/

#include <stdio.h>
#include <stdlib.h>

/*typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B);}
*/

void bubblesort(int *v, int l, int r){
    int aux;
    for(int i=l; i<r;++i){
        for(int j=l; j<r-1;++j){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    return;
}

void print(int v[], int r){
    for(int i=0; i<r;++i){
        if(i != r-1){
            printf("%d ", v[i]);
        }
        else{
            printf("%d\n", v[i]);
        }
    }
    return;
}

int main(void){
    int ar[1001], l=0, r, i=0, num;

    while(scanf("%d", &num) != EOF){
        ar[i] = num;
        i++;
    }

    r=i;

    bubblesort(ar, l, r);
    print(ar, r);
    return 0;
}