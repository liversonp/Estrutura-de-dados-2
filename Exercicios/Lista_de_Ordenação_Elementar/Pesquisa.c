/*A equipe do Fórum de GCC e Assemblers (FGA) está desenvolvendo uma ferramenta de engenharia reversa que, dado um código em linguagem de máquina, deseja convertê-lo novamente num código em linguagem de alto nível (alguma das quais o GCC dá suporte). Há inúmeros módulos que precisam ser desenvolvidos, e você faz parte da equipe de desenvolvimento. O gerente do projeto te designou a seguinte tarefa: você tem que desenvolver um programa que lê o código de uma instrução em linguagem de máquina e devolve a correspondente da linguagem de alto nível. Por exemplo, se o seu programa ler o código 20, ele deve devolver o for. Como você acabou de aprender um algoritmo de busca bem eficiente, você decide fazer um programa que carrega na memória todas as instruções, e seus respectivos códigos, e depois responde às pesquisas demandadas ao seu programa.

Entrada: A entrada é composta de diversas linhas. A primeira linha contém um inteiro nn que determina quantas instruções você precisa carregar na memória. As nn linhas seguintes contém um inteiro e uma palavra que caracterizam uma instrução: o primeiro é o código da instrução, e a segunda a palavra-chave com, no máximo, 15 caracteres. As demais linhas são inteiros que correspondem aos códigos de instruções para os quais você precisa determinar a palavra-chave correspondente. A entrada termina com EOF.

Saida: A saída é composta pela mesma quantidade de consultas feitas na entrada. Para cada inteiro consultado, você deve imprimir a palavra-chave correspondente. Se a palavra chave não fizer parte do conjunto de instruções, você deve imprimir undefined.
*/

// Não otimizado.

#include <stdio.h>
#include <stdlib.h>

typedef struct Mapa{
    int num;
    char comando[13];
} Mapa;

void Insertion(Mapa *v, int l, int r){
    Mapa aux;
    int j;

    for(int i = r; i>l; --i){
        if(v[i].num < v[i-1].num){
            aux = v[i-1];
            v[i-1] = v[i];
            v[i] = aux;
        }
    }

    for(int i = l+2; i<=r;++i){
        j = i;
        aux = v[j];

        while(aux.num < v[j-1].num){
            v[j] = v[j-1];
            j--;
        }
        v[j] = aux;
    }
    return;
}

int busca_binaria(Mapa *v, int l, int r, int num, int ant){
    int pos = (l+r)/2;
    int achei = -1;
    int sla;

    if(pos == ant){
        return -1;
    }

    if(v[pos].num == num){
        return pos;
    }

    else{
        if(v[pos].num < num){
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

int main(void){
    int n, ver, v, i, l = 0, r;
    scanf("%d", &n);
    Mapa *map = (Mapa*)malloc(n*sizeof(Mapa));

    for(i=0; i<n;++i){
        scanf("%d", &map[i].num);
        scanf(" %s", map[i].comando);
    }

    Insertion(map, 0, i-1);

    while(scanf("%d", &v) != EOF){
        ver = 0;
        l = 0;
        r = n;
        ver = busca_binaria(map, l, r, v, -1);

        if(ver == -1){
            printf("undefined\n");
        }
        else{
            printf("%s\n",map[ver].comando);
        }
    }
    free(map);
    return 0;
}