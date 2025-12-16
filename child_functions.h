#ifndef CHILD_FUNCTIONS_H
#define CHILD_FUNCTIONS_H

#include "sparse_vector.h"

size_t *linear_search(const Vector *vec, const size_t KEY);
size_t *linear_push_search(const Vector *vec, const size_t KEY);
int memory_realloc(Vector *vec, const float RESIZE_SIZE,
                   const float RESIZE_AMOUNT);
int memory_increase(Vector *vec);
int memory_decrease(Vector *vec);
#endif
