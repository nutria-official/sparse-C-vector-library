#include "sparse_vector.h"

ErrorCodes memory_realloc(Vector *vec, const float RESIZE_SIZE,
                          const float RESIZE_AMOUNT) {
  // printf("vec->size = %f\n", vec->size);
  // printf("vec->capacity / RESIZE_SIZE = %f\n", vec->capacity / RESIZE_SIZE);
  float size = vec->size;
  float capacity = vec->capacity;
  printf("capacity / RESIZE_SIZE = %f\n", capacity / RESIZE_SIZE);
  if (size <= capacity / RESIZE_SIZE) {
    capacity /= RESIZE_AMOUNT;
    printf("capacity = %f\n", capacity);
    vec->capacity = capacity;
    printf("vec->capacity = %zu\n", vec->capacity);
    void *temp_d = malloc(vec->capacity * vec->data_size);
    printf("temp_d = %p\n", temp_d);
    if (temp_d == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    }
    memcpy(temp_d, vec->data, vec->capacity * vec->data_size);
    void *temp_i = malloc(vec->capacity * sizeof(size_t));
    printf("Hi\n");
    if (temp_i == NULL) {
      return MEMORY_REALLOCATION_FAIL;
    }
    memcpy(temp_i, vec->index, vec->capacity * sizeof(size_t));
    printf("Hi\n");
    free(vec->data);
    free(vec->index);
    vec->data = temp_d;
    vec->index = temp_i;
    printf("Hi\n");
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
