#include "vector.h"

vector *vectorInit(const size_t DATA_TYPE) {
  vector *x = malloc(sizeof(vector));
  if (allocationValidation(x) == false) {
    return NULL;
  }
  x->data_size =
      DATA_TYPE + sizeof(size_t); // + sizeof(size_t) so there's space for the
                                  // element and its index.

  x->data = malloc(INITIALSIZE * x->data_size);
  if (allocationValidation(x->data) == false) {
    free(x);
    return NULL;
  }
  x->capacity = INITIALSIZE;
  x->size = 0;
  x->largest_index = 0;
  x->current_index = 0;
  return x;
}

void push(vector *x, const void *DATA) {
  if (reallocationCheck(x, 1, 1) == false) {
    return;
  }
  void *target = x->data + (x->size * x->data_size);
  memcpy(target, DATA, x->data_size - sizeof(size_t));
  target -= sizeof(size_t); // We now want to paste the index.
  memcpy(target, &x->current_index,
         sizeof(size_t)); // Pastes the index right to the data.
  x->size++;
  x->current_index++;
  if (x->largest_index < x->current_index) {
    x->largest_index = x->current_index;
  }
}

void pop(vector *x) {
  if (x->size == 0) {
    perror("No values left!");
    return;
  }
  x->size--;
  x->largest_index--;
  reallocationCheck(x, RESIZESIZE, RESIZEAMOUNT);
  return;
}

void *read(vector *x, const size_t INDEX) {
  search *receivedSearch = indexCheck(x, INDEX);
  return receivedSearch->index;
}

void insert(vector *x, const size_t INDEX, const void *DATA) {
  search *receivedSearch = indexCheck(x, INDEX);
  if (receivedIndex->index == NULL) {
    for (size_t i = 0; i < INDEX; i++) {
    }
    x->capacity =
  }
}

void freeVector(vector *x) {
  if (x == NULL) {
    perror("Vector already deleted!");
    return;
  }
  free(x->data);
  free(x);
}

bool reallocationCheck(vector *x, const size_t RESIZE_SIZE,
                       const size_t RESIZE_AMOUNT) {
  if (x->size <= x->capacity / RESIZE_SIZE) {
    x->capacity *= 2;
    void *temp = malloc(x->capacity * x->data_size);
    memcpy(temp, x->data, ceil(x->capacity / RESIZE_AMOUNT) * x->data_size);
    // void *temp = realloc(x->data, ceil(x->capacity/RESIZE_AMOUNT) *
    // x->data_size);
    if (allocationValidation(temp) == false) {
      return false;
    }
    return true;
  }
  return false;
}

search *indexCheck(vector *x, const size_t INDEX) {
  search *thisSearch;
  size_t *checkedIndex =
      x->data + x->data_size * (i + 1) -
      sizeof(size_t); // Pointer to the index of the checked element.
  for (size_t i = 0; i < x->size;
       i++) { // Linear search time, please remember to fix this later.
    checkedIndex = x->data + x->data_size * (i + 1) - sizeof(size_t);
    if (INDEX == *value) {
      thisSearch.data = x->data + (INDEX * x->data_size);
      thisSearch.index = i;
      return thisSearch;
    }
    continue;
  }
  // perror("Invalid index\n");
  thisSearch.data = NULL;
  thisSearch.index = NULL;
  return thisSearch;
}

bool allocationValidation(void *x) {
  if (x == NULL) {
    perror("Memory allocation failed\n");
    return false;
  }
  return true;
}
