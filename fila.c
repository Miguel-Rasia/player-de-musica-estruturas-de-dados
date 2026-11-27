#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct queue_{
    int size;
    int capacity;
    int inicio;
    T *v;
};

queue queue_create(int capacity){
    if (capacity <= 0){
        return NULL;
    }
    queue a = malloc(sizeof *a);
    if ( a == NULL){
        return NULL;
    }
    a->v = malloc(capacity * sizeof *(a->v));
    if (a->v == NULL){
        free(a->v);
        free(a);
        return NULL;
    }
    a->size = 0;
    a->inicio = 0;
    a->capacity=capacity;
    return a;
}

int queue_enqueue(queue a, T musica){
    if (a == NULL || musica == NULL || queue_full(a) == 1){
        return 0;
    }
    int fim = (a->inicio + a->size) % a->capacity;
    a->v[fim] = musica;
    a->size++;
    return 1;
}

int queue_dequeue (queue a, T *musica){
    if(queue_front(a,musica) == 0){
        return 0;
    }
    a->size--;
    a->inicio= (a->inicio+1) % a->capacity;
    return 1;
}

int queue_front(queue a, T *musica){
    if(a == NULL || musica == NULL || queue_empty(a) == 1){
        return 0;
    }
    *musica = a->v[a->inicio];
    return 1;
}

int queue_empty(queue a){
    if(a == NULL){
        return 0;
    }
    if(a->size == 0){
        return 1;
    }
    return 0;
}

int queue_size(queue a){
    if (a == NULL){
        return 0;
    }
    return a->size;
}

int queue_full(queue a){
    if(a == NULL){
        return 0;
    }
    if(a->size == a->capacity){
        return 1;
    }
    return 0;
}

void queue_destroy(queue a){
    if(a != NULL){
        free(a->v);
        free(a);
    }
}