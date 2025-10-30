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
  int *index;
  int size;
  int capacity;
  int data_size;
  int *largest_index; // For binary-search.
} Vector;

Vector *vectorInit(const int DATA_TYPE);
void *read(const Vector *vec, const int KEY);
void insert(Vector *vec, const int KEY, const void *DATA);
bool remove_data(Vector *vec, const int KEY);
void freeVector(Vector *vec);

#endif
