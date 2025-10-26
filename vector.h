#ifndef VECTOR_H
#define VECTOR_H

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

typedef struct { // Data the search-algorythm finds.
  void *data;
  size_t *index;
} Search;

/* Functions */

Vector *vectorInit(const size_t DATA_TYPE);
void *read(const Vector *vec, const size_t KEY);
void insert(Vector *vec, const size_t KEY, const void *DATA);
bool remove_data(Vector *vec, const size_t KEY);
void freeVector(Vector *vec);

/* Helper functions */

size_t *
binary_search(const Vector *vec,
              const size_t KEY); // Fetches the data of a given index: It's
                                 // index and a pointer to its data.
bool memory_realloc(Vector *vec, const size_t RESIZE_SIZE,
                    const float RESIZE_AMOUNT); // Checks if a given vector
                                                // should be resized or not.
bool memory_alloc(
    void *vec); // Function for checking if memory allocation failed or not.
#endif
