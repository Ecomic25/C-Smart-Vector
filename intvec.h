#ifndef INTVEC_H
#define INTVEC_H

#include <stdio.h>
#include <stdlib.h>

// --- Definição da Estrutura ---
typedef struct {
    int *data;
    int size;
    int capacity;
} IntVector;

// --- Macro de Atalho para Criação ---
#define IV_CREATE(vec_name, cap) IntVector* vec_name = intvec_create(cap)

// --- Protótipos das Funções (O "Cardápio") ---
IntVector* intvec_create(int initial_capacity);
void intvec_add(IntVector* v, int element);
void intvec_destroy(IntVector* v);
int intvec_get(IntVector* v, int index);
int intvec_get_size(IntVector* v);

#endif // INTVEC_H