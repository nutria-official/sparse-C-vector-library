#ifndef CHILD_FUNCTIONS_H
#define CHILD_FUNCTIONS_H

#include "sparse_vector.h"

size_t *binary_search(const Vector *vec, const size_t KEY, size_t lowest,
                      size_t highest);
size_t *binary_push_search(const Vector *vec, const size_t KEY,
                           const int OFFSET, size_t lowest, size_t highest);
size_t *linear_search(const Vector *vec, const size_t KEY, size_t lowest,
                      size_t highest); // For debugging.
bool *memory_realloc(Vector *vec, const size_t RESIZE_SIZE,
                     const float RESIZE_AMOUNT);
bool *memory_alloc(const void *pointer);
#endif
