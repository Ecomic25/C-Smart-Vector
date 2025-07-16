#include "intvec.h" // Inclui nosso próprio "cardápio"

IntVector* intvec_create(int initial_capacity) {
    IntVector *v = (IntVector*) malloc(sizeof(IntVector));
    if (v == NULL) return NULL;

    v->data = (int*) malloc(initial_capacity * sizeof(int));
    if (v->data == NULL) {
        free(v);
        return NULL;
    }

    v->size = 0;
    v->capacity = initial_capacity;
    
    return v;
}

void intvec_add(IntVector* v, int element) {
    if (v->size == v->capacity) {
        int new_capacity = v->capacity * 2;
        int *new_data = (int*) realloc(v->data, new_capacity * sizeof(int));
        
        if (new_data == NULL) {
            printf("Error: Failed to reallocate memory!\n");
            return;
        }
        
        v->data = new_data;
        v->capacity = new_capacity;
    }

    v->data[v->size] = element;
    v->size++;
}

void intvec_destroy(IntVector* v) {
    if (v != NULL) {
        free(v->data);
        free(v);
    }
}

int intvec_get(IntVector* v, int index) {
    if (index >= 0 && index < v->size) {
        return v->data[index];
    }
    printf("Error: Index %d is out of bounds!\n", index);
    return -1; 
}

int intvec_get_size(IntVector* v) {
    return v->size;
}