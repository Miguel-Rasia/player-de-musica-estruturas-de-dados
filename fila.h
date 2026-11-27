#ifndef fila_h
#define fila_h

#include <stdio.h>
#include <stdlib.h>
#include "musica.h"

typedef musica T; 

typedef struct queue_ *queue;

queue queue_create(int capacity); // cria a fila

int queue_enqueue(queue a, T musica); /* insere elemento ao final da fila 

retorna 1, caso a operação tenha funcionado
retorna 0, caso tenha falhado

*/
int queue_dequeue (queue a, T *musica); /* remove o primeiro elemento da fila 

retorna 1, caso a operação tenha funcionado
retorna 0, caso tenha falhado
*/
int queue_front(queue a, T *musica); /* consulta o primeiro elemento da fila 

retorna 1, caso a operação tenha funcionado
retorna 0, caso tenha falhado
*/

int queue_empty(queue a); /* verifica se a fila está vazia
retorna 1, caso a fila esteja vazia
retorna 0, caso a fila não esteja vazia
*/

int queue_size(queue a); // quantidade de elementos na fila, retornando o tamanho

int queue_full(queue a); /* verifica se a fila esta cheia
retorna 1, caso a fila esteja cheia
retorna 0, caso a fila não esteja cheia
*/

void queue_destroy(queue a); // libera a fila

#endif