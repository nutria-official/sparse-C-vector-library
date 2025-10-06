#include "vector.h"

void placeInMemory(vector *x, const size_t INDEX, const void *DATA) {
  void *target = x->data + (INDEX * x->data_size);
  memcpy(target, DATA, x->data_size - sizeof(size_t));
  target += x->data_size - sizeof(size_t); // We now want to paste the index.
  memcpy(target, &INDEX,
         sizeof(size_t)); // Pastes the index right to the data.
}

bool reallocationCheck( // This does abseloutly make no sense right now. Check
                        // for shrink or expand!?
    vector *x, const size_t RESIZE_SIZE, const float RESIZE_AMOUNT) {
  if (x->size <= x->capacity / RESIZE_SIZE) {
    x->capacity = ceil(x->capacity / RESIZE_AMOUNT);
    void *temp = malloc(x->capacity * x->data_size);
    memcpy(temp, x->data, ceil(x->capacity / RESIZE_AMOUNT) * x->data_size);
    free(x->data);
    x->data = &temp;
    return allocationValidation(temp);
  }
  return false;
}

search *find(vector *x, const size_t INDEX) {
  search *thisSearch;
  size_t *checkedIndex =
      x->data + x->data_size -
      sizeof(size_t); // Pointer to the index of the checked element.
  for (size_t i = 0; i < x->size;
       i++) { // Linear search time, please remember to fix this later.
    checkedIndex = x->data + x->data_size * (i + 1) - sizeof(size_t);
    if (INDEX == *value) {
      thisSearch->data = x->data + (INDEX * x->data_size);
      thisSearch->index = i;
      return thisSearch;
    }
    continue;
  }
  // perror("Invalid index\n");
  thisSearch->data = NULL;
  thisSearch->index = NULL;
  return thisSearch;
}

bool allocationValidation(void *x) {
  if (x == NULL) {
    perror("Memory allocation failed\n");
    return false;
  }
  return true;
}

void updateVectorProperties(
    vector *x,
    const char OPERATION) { // Perhaps make this into a switch statement?
  if (OPERATION == '+') {
    while (x->push_index !=
           NULL) { // This should be hella slow, please fix this later.
      x->push_index++;
    }
    x->size++;
    if (x->largest_index < x->push_index) {
      search *target = find(x, x->size - 1);
      x->largest_index = target->index;
    }
    reallocationCheck(x, 1, 0.5);
  } else if (OPERATION == '-') {
    if (x->push_index == x->size) {
      x->push_index--;
    }
    x->size--;
    search *target = find(x, x->size - 1);
    x->largest_index = target->index;
    reallocationCheck(x, RESIZESIZE, RESIZEAMOUNT);
  } else {
    perror("Invalid operator!");
    return;
  }
  return;
}
