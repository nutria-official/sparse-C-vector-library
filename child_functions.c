#include "main.h"

bool memory_realloc(Vector *vec, const int RESIZE_SIZE,
                    const float RESIZE_AMOUNT) {
  if (vec->size <= vec->capacity / RESIZE_SIZE) {
    vec->capacity = ceil(vec->capacity / RESIZE_AMOUNT);
    void *temp_d = malloc(vec->capacity * vec->data_size);
    void *temp_i = malloc(vec->capacity * sizeof(int));
    memcpy(temp_d, vec->data, vec->capacity * vec->data_size);
    memcpy(temp_i, vec->index, vec->capacity * sizeof(int));
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

int *binary_search(const Vector *vec, const int KEY) {
  int left = 0;
  int right = vec->size;
  int *index = NULL;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (KEY == *vec->index + (mid * sizeof(int))) {
      index = vec->index + (mid * sizeof(int));
      return index;
    }

    if (KEY > *vec->index + (mid * sizeof(int))) {
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
