#ifndef SPARSE_VECTOR_H
#define SPARSE_VECTOR_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIALSIZE 2
#define RESIZESIZE                                                             \
  4 // The proportion size at which remove() resizes the allocated memory.
#define RESIZEAMOUNT                                                           \
  2 // The proportion in which the vector gets resized when RESIZESIZE is
    // reached.

typedef struct {
  void *data;
  size_t *index;
  size_t size;
  size_t capacity;
  size_t data_size;
  size_t *largest_index; // For binary-search.
} Vector;

Vector *vectorInit(const size_t DATA_TYPE);
void *read(const Vector *vec, const size_t KEY);
void insert(Vector *vec, const size_t KEY, const void *DATA);
bool remove_data(Vector *vec, const size_t KEY);
void freeVector(Vector *vec);

#endif
