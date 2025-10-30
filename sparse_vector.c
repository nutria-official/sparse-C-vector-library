#include "main.h"
#include <string.h>

Vector *vectorInit(const int DATA_TYPE) {
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
  vec->capacity = INITIALSIZE;
  vec->size = 0;
  vec->largest_index = vec->index;
  int temp = 0;
  memcpy(vec->largest_index, &temp, sizeof(int));
  return vec;
}
void *read(const Vector *vec, const int KEY) {
  int *index = binary_search(vec, KEY);
  void *data = vec->data + (*index * vec->data_size);
  return data;
}

void insert(Vector *vec, const int KEY, const void *DATA) {
  int *index = binary_search(vec, KEY);
  printf("huh = %lu\n", *(int *)vec->index + (sizeof(int) * vec->size));
  if (index == NULL) { // Checks whether the KEY-index already has memory.
    printf("KEY = %d\n", KEY);

    if (KEY > *vec->largest_index) {

      memcpy(vec->data + (vec->data_size * vec->size), DATA, vec->data_size);
      memcpy(vec->index + (sizeof(int) * vec->size), &KEY, sizeof(int));
      vec->largest_index = (vec->index + (sizeof(int) * vec->size));

    } else {
      printf("what = %lu\n", *(int *)vec->index + (sizeof(int) * vec->size));
      // Make this later.
    }
    vec->size++;
    memory_realloc(vec, 1, 0.5);
  } else {
    printf("skibidi? = %lu\n", *(int *)vec->index + (sizeof(int) * vec->size));
    memcpy(vec->data + (vec->data_size * *index), DATA, vec->data_size);
    memcpy(vec->index + (sizeof(int) * vec->size), &KEY, sizeof(int));
  }
  return;
}

bool remove_data(Vector *vec, const int KEY) {
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
    memory_realloc(vec, RESIZESIZE, RESIZEAMOUNT);
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
