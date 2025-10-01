#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIALSIZE 2
#define RESIZESIZE                                                             \
  4 // The proportion size at which pop() resizes the allocated memory.
#define RESIZEAMOUNT                                                           \
  2 // The proportion in which the vector gets resized when RESIZESIZE is
    // reached.

typedef struct {
  void *data;
  size_t size;
  size_t capacity;
  size_t data_size; // The size of the datatype + sizeof(size_t) for indexing.
  size_t current_index; // The next index that push() should push to.
  size_t largest_index;
} vector;

typedef struct {
  void *data;
  size_t index;
} search;

vector *vectorInit(const size_t DATA_TYPE);
void push(vector *x, const void *DATA);
void pop(vector *x);
void *read(vector *x, const size_t INDEX);
void insert(vector *x, const size_t INDEX, const void *DATA);
void freeVector(vector *x);
search *indexCheck(vector *x,
                   const size_t INDEX); // Checks if an index is occupied.
bool reallocationCheck(vector *x, const size_t RESIZE_SIZE,
                       const size_t RESIZE_AMOUNT); // Checks if a given vector
                                                    // should be resized or not.
bool allocationValidation(
    void *x); // Function for checking if memory allocation failed or not.

#endif
