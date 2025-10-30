#ifndef CHILD_FUNCTIONS_H
#define CHILD_FUNCTIONS_H

#include "sparse_vector.h"

int *binary_search(const Vector *vec, const int KEY);
bool memory_realloc(Vector *vec, const int RESIZE_SIZE,
                    const float RESIZE_AMOUNT);
bool memory_alloc(void *vec);
#endif
