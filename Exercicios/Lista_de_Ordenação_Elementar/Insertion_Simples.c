/*Ordene os números lidos da entrada padrão utilizando o Algoritmo de Ordenação INSERÇÃO.

Entrada: A entrada possui um único caso de teste com uma quantidade arbitrária de números, a entrada termina quando o arquivo terminar (EOF). Os números cabem em um inteiro de 32bits.

Sabemos que cada caso de teste não possui mais que 1000 elementos.

Saída: Imprima os mesmos números ordenados de forma não decrescente. Os números devem ser separados por espaço e não deve sobrar espaço após o último número que deve ter uma quebra de linha.
*/

#include <stdio.h>
#include <stdlib.h>

void InsertionSimples(int *v, int l, int r){
    int aux;
    for(int i = l+1; i<r;++i){
        for(int j = i;j>l;--j){
            if(v[j] < v[j-1]){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
    return;
}

void print(int *v, int r){
    for(int i=0;i<r;++i){
        if(i !=r-1){
            printf("%d ", v[i]);
        }
        else{
            printf("%d\n", v[i]);
        }
    }
    return;
}

int main(void){
    int ar[1001], l=0, i=0;
    while(scanf("%d", &ar[i]) != EOF){
        i++;
    }
    
    InsertionSimples(ar, l, i);

    print(ar, i);

    return 0;
}