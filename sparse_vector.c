#include "sparse_vector.h"
#include "child_functions.h"
#include <string.h>

Vector *vectorInit(const size_t DATA_TYPE) {
  Vector *vec = malloc(sizeof(Vector));
  if (vec == NULL) {
    return NULL;
  }
  vec->data_size = DATA_TYPE;
  printf("vec->data_size: %zu\n", vec->data_size);
  printf("INITIALSIZE: %d\n", INITIALSIZE);
  printf("Allocated memory: %zu\n", INITIALSIZE * vec->data_size);
  vec->data = malloc(INITIALSIZE * vec->data_size);
  if (vec->data == NULL) {
    free(vec);
    return NULL;
  }
  vec->index = malloc(INITIALSIZE * sizeof(size_t));
  if (vec->index == NULL) {
    free(vec);
    return NULL;
  }

  vec->capacity = INITIALSIZE;
  printf("vec->capacity: %zu\n", vec->capacity);
  vec->size = 0;
  vec->largest_index = NULL;
  return vec;
}
void *read(const Vector *vec, const size_t KEY) {
  size_t *index = linear_search(vec, KEY);
  if (index == NULL) {
    return NULL;
  } else {
    return vec->data + (index - vec->index) / sizeof(size_t) * vec->data_size;
  }
}

ErrorCodes insert(Vector *vec, const size_t KEY, const void *DATA) {
  size_t *index = linear_search(vec, KEY);
  if (index == NULL) {
    if (vec->largest_index == NULL || KEY > *vec->largest_index) {
      memcpy((vec->data + (vec->data_size * vec->size)), DATA, vec->data_size);
      memcpy((vec->index + (sizeof(size_t) * vec->size)), &KEY, sizeof(size_t));
    } else {
      size_t *push_from = linear_push_search(vec, KEY);
      size_t relative_index =
          *(size_t *)(vec->data + (push_from - vec->index) / sizeof(size_t));
      for (size_t i = vec->size; i > relative_index; i--) {
        memcpy(vec->data + vec->data_size * i,
               vec->data + vec->data_size * (i - 1), sizeof(size_t));
        memcpy(vec->index + (sizeof(size_t) * i),
               vec->index + sizeof(size_t) * (i - 1), sizeof(size_t));
      }
      memcpy(vec->data + relative_index * vec->data_size, DATA, vec->data_size);
      memcpy(vec->index + relative_index * sizeof(size_t), &KEY,
             sizeof(size_t));
    }
    vec->largest_index = (vec->index + sizeof(size_t) * vec->size);
    vec->size++;

    if (memory_realloc(vec, 1, 0.5) == MEMORY_REALLOCATION_FAIL) {
      return MEMORY_REALLOCATION_FAIL;
    };
  } else {
    memcpy(vec->data + (index - vec->index) / sizeof(size_t) * vec->data_size,
           DATA, vec->data_size);
    memcpy(vec->index + (sizeof(size_t) * vec->size), &KEY, sizeof(size_t));
  }
  return NO_ERROR;
}

ErrorCodes remove_data(Vector *vec, const size_t KEY) {
  size_t *index = linear_search(vec, KEY);
  if (index == NULL) {
    return ERROR;
  } else {
    vec->size--;
    for (size_t i = (index - vec->index) / sizeof(size_t); i < vec->size; i++) {
      memcpy(vec->data + (i * vec->data_size),
             vec->data + (i + 1) * vec->data_size, vec->data_size);

      memcpy(vec->index + (i * sizeof(size_t)),
             vec->index + (i + 1) * sizeof(size_t), sizeof(size_t));
    }
    // return memory_realloc(vec, RESIZESIZE, RESIZEAMOUNT);
    return NO_ERROR;
  }
}

ErrorCodes freeVector(Vector *vec) {
  if (vec == NULL) {
    return ERROR;
  }
  free(vec->data);
  free(vec->index);
  free(vec);
  return NO_ERROR;
}
