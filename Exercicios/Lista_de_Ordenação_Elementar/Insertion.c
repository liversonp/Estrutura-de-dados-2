/* Ordene os números lidos da entrada padrão utilizando o Algoritmo de Ordenação INSERÇÃO.

Entrada: A entrada possui um único caso de teste com uma quantidade arbitrária de números, a entrada termina quando o arquivo terminar (EOF). Os números cabem em um inteiro de 32bits.

Sabemos que cada caso de teste não possui mais que 50000 elementos.

Saída: Imprima os mesmos números ordenados de forma não decrescente. Os números devem ser separados por espaço e não deve sobrar espaço após o último número que deve ter uma quebra de linha.
*/

#include <stdio.h>
#include <stdlib.h>

void Insertion(int *v, int l, int r){
    int aux;
    int j;

    for(int i = r; i>l; --i){
        if(v[i] < v[i-1]){
            aux = v[i-1];
            v[i-1] = v[i];
            v[i] = aux;
        }
    }

    for(int i = l+2; i<=r;++i){
        j = i;
        aux = v[j];

        while(aux < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = aux;
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
    int ar[500001], l=0, i=0;
    while(scanf("%d", &ar[i]) != EOF){
        i++;
    }
    
    Insertion(ar, l, i-1);

    print(ar, i);

    return 0;
}