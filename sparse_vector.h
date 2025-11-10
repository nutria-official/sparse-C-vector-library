#ifndef SPARSE_VECTOR_H
#define SPARSE_VECTOR_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIALSIZE 100
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

Vector *vectorInit(int DATA_TYPE);
void *read(Vector *vec, int KEY);
void insert(Vector *vec, int KEY, void *DATA);
bool remove_data(Vector *vec, int KEY);
void freeVector(Vector *vec);

#endif
