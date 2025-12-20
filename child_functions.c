#include "sparse_vector.h"
#include <stdlib.h>

int memory_increase(Vector *vec) {
  if (vec->size == vec->capacity) {
    vec->capacity *= 2;
    size_t *temp_i = realloc(vec->index, vec->capacity * sizeof(size_t));
    if (temp_i == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    } else {
      vec->index = temp_i;
      vec->largest_index = vec->index + sizeof(size_t) * (vec->size - 1);
    }
    void *temp_d = realloc(vec->data, vec->capacity * vec->data_size);
    if (temp_d == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    } else {
      vec->data = temp_d;
    }
  }
  return NO_ERROR;
}

int memory_decrease(Vector *vec) {
  float capacity = vec->capacity;
  size_t new_capacity = capacity / RESIZESIZE;
  if (vec->size <= new_capacity) {
    vec->capacity = new_capacity;
    size_t *temp_d = realloc(vec->data, vec->capacity * vec->data_size);
    if (temp_d == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    }
    size_t *temp_i = realloc(vec->index, vec->capacity * sizeof(size_t));
    if (temp_i == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    }
  }
  return NO_ERROR;
}

size_t *linear_search(const Vector *vec, const size_t KEY) {
  for (size_t i = 0; i < vec->size; i++) {
    if (KEY == *(size_t *)(vec->index + (i * sizeof(size_t)))) {
      return vec->index + (i * sizeof(size_t));
    }
  }
  return NULL;
}

size_t *linear_push_search(const Vector *vec, const size_t KEY) {
  for (size_t i = 0; i < vec->size; i++) {
    printf("index: %zu, push_search: %zu\n", i,
           *(size_t *)vec->index + (i * sizeof(size_t)));
    if (KEY < *(size_t *)(vec->index + (i * sizeof(size_t)))) {
      return vec->index + (i * sizeof(size_t));
    }
  }
  return NULL;
}
