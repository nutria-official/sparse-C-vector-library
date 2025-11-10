#include "main.h"

bool *memory_realloc(Vector *vec, const size_t RESIZE_SIZE,
                     const float RESIZE_AMOUNT) {
  static bool return_value = true;
  if (vec->size <= vec->capacity / RESIZE_SIZE) {
    vec->capacity /= RESIZE_AMOUNT + 1;
    void *temp_d = malloc(vec->capacity * vec->data_size);
    if (*(bool *)memory_alloc(temp_d) == false) {
      return NULL;
    }
    memcpy(temp_d, vec->data, vec->capacity * vec->data_size);
    void *temp_i = malloc(vec->capacity * sizeof(size_t));
    if (*(bool *)memory_alloc(temp_i) == false) {
      return NULL;
    }
    memcpy(temp_i, vec->index, vec->capacity * sizeof(size_t));
    free(vec->data);
    free(vec->index);
    vec->data = temp_d;
    vec->index = temp_i;
    return_value = true;
    return &return_value;
  }
  return_value = false;
  return &return_value;
}

size_t *binary_search(const Vector *vec, const size_t KEY, size_t lowest,
                      size_t highest) {
  while (lowest < highest) {
    size_t middle = lowest + (highest - lowest) / 2;
    if (KEY == *(size_t *)(vec->index + (middle * sizeof(size_t)))) {
      return vec->index + (middle * sizeof(size_t));
    }
    if (KEY > *(size_t *)(vec->index + (middle * sizeof(size_t)))) {
      lowest = middle + 1;
    } else {
      highest = middle - 1;
    }
  }
  return NULL;
}
size_t *binary_push_search(const Vector *vec, const size_t KEY,
                           const int OFFSET, size_t lowest, size_t highest) {
  while (lowest < highest) {
    size_t middle = lowest + (highest - lowest) / 2;
    if (KEY == *(size_t *)(vec->index + (middle * sizeof(size_t)))) {
      return vec->index + (middle * sizeof(size_t));
    }
    if (KEY > *(size_t *)(vec->index + (middle * sizeof(size_t)))) {
      lowest = middle + 1;
    } else {
      highest = middle - 1;
    }
  }
  return vec->index + ((lowest + 1) * sizeof(size_t));
}

size_t *linear_search(const Vector *vec, const size_t KEY, size_t lowest,
                      size_t highest) {
  size_t *index = NULL;
  for (size_t i = lowest; i < highest; i++) {
    if (KEY == *(size_t *)(vec->index + (i * sizeof(size_t)))) {
      index = vec->index + (i * sizeof(size_t));
      return index;
    }
  }
  return index;
}

bool *memory_alloc(const void *pointer) {
  static bool return_value = true;
  if (pointer == NULL) {
    perror("Memory allocation failed.\n");
    return NULL;
  }
  return &return_value;
}
