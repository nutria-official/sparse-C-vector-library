#include "sparse_vector.h"
#include <stdlib.h>

int memory_increase(Vector *vec) {
  if (vec->size == vec->capacity) {
    vec->capacity *= 2;
    int *temp_i = realloc(vec->index, vec->capacity * sizeof(size_t));
    if (temp_i == NULL) {
      return MEMORY_REALLOCATION_FAIL;

    } else {
      vec->largest_index = vec->index + sizeof(size_t) * (vec->size - 1);
    }
    size_t *temp_d = realloc(vec->data, vec->capacity * vec->data_size);
    if (temp_d == NULL) {
      return MEMORY_REALLOCATION_FAIL;
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

int memory_realloc(Vector *vec, const float RESIZE_SIZE,
                   const float RESIZE_AMOUNT) {
  printf("bam\n");
  float size = vec->size;
  float capacity = vec->capacity;
  printf("vec->capacity / RESIZE_AMOUNT = %f\n", vec->capacity / RESIZE_SIZE);
  if (size == capacity / RESIZE_SIZE) {
    capacity /= RESIZE_AMOUNT;
    vec->capacity = capacity;

    printf("capacity = %zu\n", vec->capacity);

    printf("vec->capacity * vec->data_size = %zu\n",
           vec->capacity * vec->data_size);
    void *temp_d = realloc(vec->data, vec->capacity * vec->data_size);
    if (temp_d == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    }
    vec->data = temp_d;

    printf("sizeof(size_t) = %zu\n", sizeof(size_t));
    printf("vec->capacity * sizeof(size_t) = %zu\n",
           vec->capacity * sizeof(size_t));

    return 1;
    void *temp_i = realloc(vec->index, vec->capacity * sizeof(size_t));
    //  return 1;
    if (temp_i == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    }

    vec->index = temp_i;
    vec->largest_index = vec->index + (vec->size - 1) * sizeof(size_t);
    printf("vec->largest_index = %zu\n", *vec->largest_index);
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
    if (KEY < *(size_t *)(vec->index + (i * sizeof(size_t)))) {
      return vec->index + (i * sizeof(size_t));
    }
  }
  return NULL;
}
