#ifndef CHILD_FUNCTIONS_H
#define CHILD_FUNCTIONS_H

#include "sparse_vector.h"

int *binary_search(Vector *vec, int KEY);
int *linear_search(Vector *vec, int KEY); // For debugging.
bool *memory_realloc(Vector *vec, int RESIZE_SIZE, float RESIZE_AMOUNT);
bool *memory_alloc(void *vec);
#endif
