#include "vector.h"

bool memory_realloc(Vector *vec, const size_t RESIZE_SIZE,
                    const float RESIZE_AMOUNT) {
  if (vec->size <= vec->capacity / RESIZE_SIZE) {
    vec->capacity = ceil(vec->capacity / RESIZE_AMOUNT);
    void *temp_d = malloc(vec->capacity * vec->data_size);
    void *temp_i = malloc(vec->capacity * sizeof(size_t));
    memcpy(temp_d, vec->data, vec->capacity * vec->data_size);
    memcpy(temp_i, vec->index, vec->capacity * sizeof(size_t));
    free(vec->data);
    free(vec->index);
    vec->data = temp_d;
    vec->index = temp_i;

    if (memory_alloc(temp_d) * memory_alloc(temp_i) == false) {
      return false;
    }
    return true;
  }
  return true;
}

size_t *binary_search(const Vector *vec, const size_t KEY) {
  size_t left = 0;
  size_t right = vec->size;
  size_t *index = NULL;

  while (left < right) {
    size_t mid = left + (right - left) / 2;
    // printf("%zu mid\n", mid);

    if (KEY == *vec->index + (mid * sizeof(size_t))) {
      index = vec->index + (mid * sizeof(size_t));
      return index;
    }

    if (KEY > *vec->index + (mid * sizeof(size_t))) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return NULL;
}

bool memory_alloc(void *vec) {
  if (vec == NULL) {
    perror("Memory allocation failed.\n");
    return false;
  }
  return true;
}
