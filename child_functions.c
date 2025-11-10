#include "main.h"

bool *memory_realloc(Vector *vec, int RESIZE_SIZE, float RESIZE_AMOUNT) {
  bool *return_value = NULL;
  if (vec->size <= vec->capacity / RESIZE_SIZE) {
    vec->capacity /= RESIZE_AMOUNT + 1;
    void *temp_d = malloc(vec->capacity * vec->data_size);
    if (memory_alloc(temp_d) == false) {
      return NULL;
    }
    memcpy(temp_d, vec->data, vec->capacity * vec->data_size);
    void *temp_i = malloc(vec->capacity * sizeof(int));
    if (memory_alloc(temp_i) == false) {
      return NULL;
    }
    memcpy(temp_i, vec->index, vec->capacity * sizeof(int));
    free(vec->data);
    free(vec->index);
    vec->data = temp_d;
    vec->index = temp_i;
    return true;
  }
  return true;
}

int *binary_search(Vector *vec, int KEY) {
  int left = 0;
  int right = vec->size;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (KEY == *(int *)(vec->index + (mid * sizeof(int)))) {
      return vec->index + (mid * sizeof(int));
    }
    if (KEY > *(int *)(vec->index + (mid * sizeof(int)))) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return NULL;
}

int *linear_search(Vector *vec, int KEY) {
  int *index = NULL;
  for (int i = 0; i < vec->size; i++) {
    if (KEY == *(int *)(vec->index + (i * sizeof(int)))) {
      index = vec->index + (i * sizeof(int));
      return index;
    }
  }
  return index;
}

bool *memory_alloc(void *vec) {
  if (vec == NULL) {
    perror("Memory allocation failed.\n");
    return NULL;
  }
  return true;
}
