# Edazinho da Dominação

## 1 Preâmbulo

EDAzinho é uma jovem célula que busca as complexidades das coisas da vida. Para conseguir encontrar as complexidades nosso nobre guerreiro precisa dominar uma grande porção de terreno.

A dominação pelos terrenos é tão interessante que EDAzinho pensou que poderia maximizar os custos dos terrenos conquistados.

## 2 Objetivo

O objetivo do jogo é crescer o máximo possível adquirindo a maior quantidade de pontos.

### 2.1 Cálculo dos pontos

- D é o conjunto de áreas dominadas
- Pi pontuação de uma área dominada
- T é o tempo em segundos da execução do seu programa
- M  é a memória em MegaBytes utilizada pelo seu programa 

Logo a pontuação é dada por: Pontos=∑|D|i=0(Pi)−T∗100−M∗10

## 3 MAPA

O mapa deste jogo pode ser visto como uma matriz infinita, em qualquer direção, o jogador começa em uma posição aleatória definida logo no início da partida.

O mapa é uma incógnita para o jogador, e para isso precisa perguntar ao árbitro as pontuações das casas adjacentes.

## 4 Regras

O jogo é baseado em um sistema de turnos, mesmo sendo single player, e um conjunto limitado de operações podem ser executados a cada turno.

### 4.1 Início do jogo

O início do jogo é marcado por uma única linha, que deve ser lida da entrada padrão, contendo 4 números inteiros L,C,P,T representando, respectivamente:

- L - a linha que o jogador começa ( −263≤L≤263 )
- C - a coluna que o jogador começa ( −263≤C≤263 )
- P - a quantidade de pontos adquiras na posição inicial ( −263≤P≤263 )
- T - o total de turnos para a partida ( $ 10 ≤ T ≤ 231$ )

### 4.2 Comandos possíveis

A cada turno o jogador poderá efetuar um conjunto de operações e são elas:

- sondar L' C'
    - Operação que para perguntar quantos pontos uma célula (L',C') possui. Note que esta célula deve ser adjacente a um Edazinho.
    - Você pode executar esta operação baseada na quantidade de Edazinhos existentes, i.e, para 1 Edazinho pode executar 1 vez, para 2 Edazinhos 2 vezes e assim por diante
    - O jogador só pode efetuar sondagens de regiões adjacentes a EDAzinhos de turnos anteriores, ou seja, as novas regiões adjacentes de um edazinho recém dominado não contam.
dominar L' C'
    - Operação para dominar uma célula (L',C'), você só pode efetuar esta operação em células sondadas em turnos anteriores
    - você pode executar esta operação no máximo 1 vez por turno
- fimturno
    - Operação que indica fim das operações de turno para o árbitro do jogo.

#### 4.2.1 Comandos inválidos

Sempre que o seu programa executar uma operação ilegal/inválida, todos os Edazinhos serão mortos e seu programa será encerrado com 0 pontos.

### 4.3 Respostas dos comandos

Cada comando executado em um turno retornará respostas:

- sondagem L' C' P
    - é o retorno da operação sondar, indicando que a sondagem na casa (L',C') indicou P pontos
- dominacao P
    - é o retorno da operação dominar indicando quantos pontos foram obtidos da dominação