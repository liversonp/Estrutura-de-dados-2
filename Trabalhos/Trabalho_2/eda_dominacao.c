#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t; t = A; A = B; B = t; }
#define nopai(A) (A/2)
#define noesquerda(A) (A*2)
#define nodireita(A) ((A*2)+1)
#define primo 104729

typedef long long int llint;

typedef struct noLista{
    llint x;
    llint y;
    struct noLista* next;
}noLista;

typedef struct lista{
    noLista* head;
    llint tam;
}Lista;

typedef struct item{
    llint x;
    llint y;
    llint pontuacao;
}Item;

Lista* sondados[104730];
Lista* edazinhos;

static Item* pq;
static int N;
bool dominouVerif;
int sla;
//------------------------------------------- Lista

Lista* initLista(){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->head = NULL;
    novaLista->tam = 0;
    return novaLista;
}

void listaPush(Lista* list, llint x, llint y){
    noLista* nova = (noLista*)malloc(sizeof(noLista)); 
    nova->x = x;
    nova->y = y;
    if(list->head == NULL){
        nova->next = list->head;
        list->head = nova;
    }

    else{
        noLista* aux = list->head;

        while(aux->next != NULL){
            aux = aux->next;
        }
        nova->next = aux->next;
        aux->next = nova;
    }
    list->tam++;
}

void listaPop(Lista* list){
    if(list->head != NULL){
        noLista* aux = list->head;
        list->head = aux->next;
        free(aux);
    }
    list->tam--;
}

void printaLista(Lista* list){
    if(list->head != NULL){
        noLista* aux = list->head;
        while(aux != NULL){
            printf("x:%lld y:%lld\n", aux->x, aux->y);
            aux = aux->next;
        }
    }
    else{
        printf("LISTA VAZIA\n");
    }
}

//------------------------------------------- Fila de prioridade

void PQinit (llint maxN){
    pq = (Item*)malloc(sizeof(Item)*(maxN+1));
    N = 0;
}

bool PQempty(){
    return (N == 0);
}

void fixUp(int k){
    if(k>1 && less(pq[nopai(k)].pontuacao, pq[k].pontuacao)){
        exch(pq[nopai(k)],pq[k]);
        fixUp(nopai(k));
    }
}

void fixDown(int k){
    int aux = k;

    if(noesquerda(k) < N && less(pq[aux].pontuacao, pq[noesquerda(k)].pontuacao)){
        aux = noesquerda(k);
    }

    if(nodireita(k) < N && less(pq[aux].pontuacao, pq[nodireita(k)].pontuacao)){
        aux = nodireita(k);
    }

    if(aux != k){
        exch(pq[aux], pq[k]);
        fixDown(aux);
    }
}

void PQinsert(Item novo){
    if(sla == 6){
        fixDown(1);
        sla = 0;
    }

    if(N == 128){
        pq[N-sla] = novo;
        fixUp(N-sla);
        sla++;
    }
    else{
        pq[++N] = novo;
        fixUp(N);
    }
}

Item PQdelMax(){
    exch(pq[1], pq[N]);
    N--;
    fixDown(1);
    return pq[N+1];
}

void puxaFila(llint x, llint y, llint pontuacao){
    Item novo;
    novo.x = x;
    novo.y = y;
    novo.pontuacao = pontuacao;
    PQinsert(novo);
}

llint cHash(llint x){
    return (abs(x)%primo);
}

bool naLista(Lista* list, llint x, llint y){
    bool encontrado = false;
    if(list->head != NULL){
        noLista* aux = list->head;
        while(aux != NULL){
            if(aux->x == x && aux->y == y){
                encontrado = true;
            }
            aux = aux->next;
        }
    }
    return encontrado;
}

noLista* addEdazinho(){
    noLista*  adicionado = (noLista*)malloc(sizeof(noLista));
    if(!PQempty()){
        char comando[15];
        llint pontos;
        printf("dominar %lld %lld\n",pq[1].x,pq[1].y);
        fflush(stdout);
        scanf(" %s", comando);
        scanf(" %lld", &pontos);
        adicionado->x = pq[1].x;
        adicionado->y = pq[1].y;
        dominouVerif = true;
        PQdelMax();
    }
    return adicionado;
}

void dispSondar(){
    
    noLista *head = edazinhos->head;
    llint hcodemenor;
    llint hcode;
    llint hcodemaior;
    char comando[15];
    bool retirei;
    llint posX,posY, pontos;
    noLista* prev = edazinhos->head;
    //para x-1
    while(head != NULL){
        hcodemenor = cHash(head->x-1);
        hcode = cHash(head->x);
        hcodemaior = cHash(head->x+1);
        retirei = false;

        if(!naLista(sondados[hcodemaior],head->x+1,head->y+1)){
            printf("sondar %lld %lld\n", head->x+1, head->y+1);
            fflush(stdout);
            listaPush(sondados[hcodemaior],head->x+1,head->y+1);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }

        else if(!naLista(sondados[hcodemenor], head->x-1, head->y-1)){
            printf("sondar %lld %lld\n", head->x-1, head->y-1);
            fflush(stdout);
            listaPush(sondados[hcodemenor], head->x-1, head->y-1);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }

        else if(!naLista(sondados[hcodemaior], head->x+1, head->y-1)){
            printf("sondar %lld %lld\n", head->x+1, head->y-1);
            fflush(stdout);
            listaPush(sondados[hcodemaior], head->x+1, head->y-1);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }

        else if(!naLista(sondados[hcodemenor], head->x-1, head->y+1)){
            printf("sondar %lld %lld\n", head->x-1, head->y+1);
            fflush(stdout);
            listaPush(sondados[hcodemenor], head->x-1, head->y+1);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }

        else if(!naLista(sondados[hcodemaior],head->x+1,head->y)){
            printf("sondar %lld %lld\n", head->x+1, head->y);
            fflush(stdout);
            listaPush(sondados[hcodemaior],head->x+1,head->y);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }

        else if(!naLista(sondados[hcodemenor], head->x-1, head->y)){
            printf("sondar %lld %lld\n", head->x-1, head->y);
            fflush(stdout);
            listaPush(sondados[hcodemenor], head->x-1, head->y);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }

        //para x
        else if(!naLista(sondados[hcode],head->x,head->y-1)){
            printf("sondar %lld %lld\n", head->x, head->y-1);
            fflush(stdout);
            listaPush(sondados[hcode], head->x, head->y-1);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }

        else if(!naLista(sondados[hcode], head->x,head->y+1)){
            printf("sondar %lld %lld\n", head->x, head->y+1);
            fflush(stdout);
            listaPush(sondados[hcode], head->x, head->y+1);
            scanf(" %s", comando);
            scanf(" %lld %lld %lld", &posX, &posY, &pontos);
            puxaFila(posX,posY,pontos);
        }
        
        else{
            if(head == edazinhos->head){
                listaPop(edazinhos);
            }
            else{
                noLista* aux = head;
                prev->next = aux->next;
                head = prev->next;
                edazinhos->tam--;
                free(aux);
                retirei = true;
            }
        }
        if(!retirei){
            prev = head;
            head = head->next;
        }   
    }
}


int main(){
    bool game = true;
    noLista* dominou = NULL;
    llint xInicial, yInicial, pontoInicial, turnos;
    llint hcode;
    llint nSondagens=1;
    sla =0;

    PQinit(128);
    for(int i=0;i<primo+1;i++){
        sondados[i] = initLista();
    }
    edazinhos = initLista();

    scanf("%lld %lld %lld %lld", &xInicial, &yInicial, &pontoInicial, &turnos);

    listaPush(edazinhos, xInicial,yInicial);
    hcode = cHash(xInicial);
    listaPush(sondados[hcode],xInicial,yInicial);

    llint i = 0;
    while(game){
        dominouVerif = false;
        if(i == turnos-1){
            game = false;
        }
        dominou = addEdazinho();
        dispSondar();
        
        if(dominouVerif == true){
            listaPush(edazinhos, dominou->x, dominou->y);
        }

        printf("fimturno\n");
        fflush(stdout);
        i++;
    }
    return 0;
}