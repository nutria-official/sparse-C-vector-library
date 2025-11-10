#include "child_functions.h"
#include "main.h"
#include <string.h>

Vector *vectorInit(int DATA_TYPE) {
  Vector *vec = malloc(sizeof(Vector));
  if (memory_alloc(vec) == false) {
    return NULL;
  }
  vec->data_size = DATA_TYPE;
  vec->data = malloc(INITIALSIZE * vec->data_size);
  if (memory_alloc(vec->data) == false) {
    free(vec);
    return NULL;
  }
  vec->index = malloc(INITIALSIZE * sizeof(int));
  if (memory_alloc(vec->index) == false) {
    free(vec);
    return NULL;
  }
  vec->capacity = INITIALSIZE - 1;
  vec->size = 0;
  vec->largest_index = NULL;
  return vec;
}
void *read(Vector *vec, int KEY) {
  int *index = binary_search(vec, KEY);
  if (index == NULL) {
    perror("Read element does not exist!\n");
  }
  void *data = vec->data + (*index * vec->data_size);
  return data;
}

void insert(Vector *vec, int KEY, void *DATA) {
  int *index = binary_search(vec, KEY);
  if (index == NULL) { // Checks whether the KEY-index already has memory.
    if (vec->largest_index == NULL || KEY > *vec->largest_index) {
      memcpy((vec->data + (vec->data_size * vec->size)), DATA, vec->data_size);
      memcpy((vec->index + (sizeof(int) * vec->size)), &KEY, sizeof(int));
      vec->largest_index = (vec->index + (sizeof(int) * vec->size));
      int *temp = (vec->index + (sizeof(int) * vec->size));
    } else {
      int *temp = vec->index + (sizeof(int) * vec->size);
      int *push = binary_search(vec, 0);
      int counter = 0;
      while (*push < KEY) {
        counter++;
        push =
            binary_search(vec, *(int *)(vec->index + (sizeof(int) * counter)));
      }
      for (int i = vec->size - 1; i >= *push; i--) {
        memcpy(vec->data + (vec->data_size * (i + 1)),
               vec->data + (vec->data_size * i), sizeof(int));
      }
      vec->largest_index = vec->largest_index + sizeof(int);
      // memory_realloc(vec);
    }
    vec->size++;
    // memory_realloc(vec, 1, 0.5);
  } else {
    printf("Index: %d\n", *index);
    int *temp = vec->index + (sizeof(int) * vec->size);
    memcpy(vec->data + (vec->data_size * *(int *)(index - vec->index)), DATA,
           vec->data_size);
    memcpy(vec->index + (sizeof(int) * vec->size), &KEY, sizeof(int));
  }
  return;
}

bool remove_data(Vector *vec, int KEY) {
  int *index = binary_search(vec, KEY);
  if (index == NULL) {
    perror("Element does not exist\n");
    return false;
  } else {
    vec->size--;
    for (int i = *index; i < vec->size; i++) {
      memcpy(vec->data + (i * vec->data_size),
             vec->data + (i + 1) * vec->data_size, vec->data_size);

      memcpy(vec->index + (i * sizeof(int)), vec->index + (i + 1) * sizeof(int),
             sizeof(int));
    }
    // memory_realloc(vec, RESIZESIZE, RESIZEAMOUNT);
    return true;
  }
}

void freeVector(Vector *vec) {
  if (vec == NULL) {
    perror("Vector already deleted!");
    return;
  }
  free(vec->data);
  free(vec->index);
  free(vec);
}
