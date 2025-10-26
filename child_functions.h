#ifndef CHILD_FUNCTIONS_H
#define CHILD_FUNCTIONS_H

#include "sparse_vector.h"

size_t *binary_search(const Vector *vec, const size_t KEY);
bool memory_realloc(Vector *vec, const size_t RESIZE_SIZE,
                    const float RESIZE_AMOUNT);
bool memory_alloc(void *vec);
#endif
