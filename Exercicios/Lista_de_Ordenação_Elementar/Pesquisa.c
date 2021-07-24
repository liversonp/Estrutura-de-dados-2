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

void ordena(Mapa *map, int l, int r){
    Mapa aux;
    int j;

    for(int i = r-1; i>l; --i){
        if(map[i].num < map[i-1].num){
            aux = map[i-1];
            map[i-1] = map[i];
            map[i] = aux;
        }
    }
}

int main(void){
    int n, ver = 0, v, i, p, rep, l = 0, r;
    scanf("%d", &n);
    Mapa *map = (Mapa*)malloc(n*sizeof(Mapa));

    for(i=0; i<n;++i){
        scanf("%d", &map[i].num);
        scanf(" %s", map[i].comando);
        ordena(map, 0, i);
    }
    
    Mapa aux = map[i-2];
    map[i-2] = map[i-1];
    map[i-1] = aux;
    
    r = n;
    

    while(scanf("%d", &v) != EOF){
        ver = 0;
        l = 0;
        r = n;

        int *vis = (int*)calloc(n,sizeof(int));

        while(ver != 1 && vis[l + (r - l)/2] == 0){
            p = l + (r - l)/2;
            
            if(map[p].num == v){
                printf("%s\n", map[p].comando);
                ver = 1;
            }

            else{
                vis[p] = 1;
                if(map[p].num > v){
                    r = p;
                }

                else{
                    l = p;
                }
            }
        }

        if(ver == 0){
            printf("undefined\n");
        }
    }
    return 0;
}