#include "main.h"
#include <string.h>

Vector *vectorInit(const size_t DATA_TYPE) {
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
  vec->index = malloc(INITIALSIZE * sizeof(size_t));
  if (memory_alloc(vec->index) == false) {
    free(vec);
    return NULL;
  }
  vec->capacity = INITIALSIZE;
  vec->size = 0;
  vec->largest_index = vec->index;
  return vec;
}
void *read(const Vector *vec, const size_t KEY) {
  size_t *index = binary_search(vec, KEY);
  void *data = vec->data + (*index * vec->data_size);
  return data;
}

void insert(Vector *vec, const size_t KEY, const void *DATA) {
  size_t *index = binary_search(vec, KEY);
  if (index == NULL) { // Checks whether the KEY-index already has memory.
    if (KEY > *vec->largest_index) {
      memcpy(vec->data + (vec->data_size * vec->size), DATA, vec->data_size);
      memcpy(vec->index + (sizeof(size_t) * vec->size), &KEY, sizeof(size_t));
      vec->largest_index = vec->index + (sizeof(size_t) * vec->size);
    } else {
      // Make this later.
    }
    vec->size++;
    memory_realloc(vec, 1, 0.5);
  } else {
    memcpy(vec->data + (vec->data_size * *index), DATA, vec->data_size);
    memcpy(vec->index + (sizeof(size_t) * vec->size), &KEY, sizeof(size_t));
  }
  return;
}

bool remove_data(Vector *vec, const size_t KEY) {
  size_t *index = binary_search(vec, KEY);
  if (index == NULL) {
    perror("Element does not exist\n");
    return false;
  } else {
    vec->size--;
    for (size_t i = *index; i < vec->size; i++) {
      memcpy(vec->data + (i * vec->data_size),
             vec->data + (i + 1) * vec->data_size, vec->data_size);

      memcpy(vec->index + (i * sizeof(size_t)),
             vec->index + (i + 1) * sizeof(size_t), sizeof(size_t));
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
