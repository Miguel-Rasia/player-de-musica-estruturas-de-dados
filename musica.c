#include <stdio.h>
#include <stdlib.h>
#include "musica.h"

struct musica_ {
    char titulo[100];
    char artista[100];
    int duracao_em_segundos;
};


musica criar_musica(void){
    musica x = malloc(sizeof *x);
    if (x == NULL){
        return NULL;
    }
    x->titulo[0] = '\0';
    printf("Digite o titulo:\n");
    scanf(" %99[^\n]", x->titulo);

    x->artista[0] = '\0';
    printf("Digite o artista:\n");
    scanf(" %99[^\n]", x->artista);

    printf("Digite a duração da música em segundos:\n");
    scanf("%d",&x->duracao_em_segundos);
    
    return x;

}

void imprimir_tocando_agora(musica x){
    if (x == NULL){
        return;
    }
    int minutos = x->duracao_em_segundos/60;
    int segundos = x->duracao_em_segundos%60;

    printf("Você está ouvindo: %s - %s (%02d:%02d)\n", x->titulo, x->artista, minutos, segundos);
    
    return;
}

void destruir_musica(musica x){
    if (x == NULL){
        return;
    }
    free(x);
    x = NULL;
    return;
}