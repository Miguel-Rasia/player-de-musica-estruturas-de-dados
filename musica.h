#ifndef musica_h
#define musica_h

#include <stdio.h>
#include <stdlib.h>

typedef struct musica_ *musica;

musica criar_musica(void);

void imprimir_tocando_agora(musica a);

void destruir_musica(musica x);

#endif