#ifndef SPARSE_VECTOR_H
#define SPARSE_VECTOR_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIALSIZE 2
#define RESIZESIZE 4
#define RESIZEAMOUNT 2
typedef enum {
  NO_ERROR,
  ERROR,
  NO_ELEMENT_AT_INDEX,
  MEMORY_ALLOCATION_FAIL,
  MEMORY_REALLOCATION_FAIL,
} ErrorCodes;

typedef struct {
  void *data;
  size_t *index;
  size_t size;
  size_t capacity;
  size_t data_size;
  size_t *largest_index;
} Vector;

Vector *vectorInit(const size_t DATA_TYPE);
void *read(const Vector *vec, const size_t KEY);
int insert(Vector *vec, const size_t KEY, const void *DATA);
int remove_data(Vector *vec, const size_t KEY);
int freeVector(Vector *vec);

#endif
