#include <stdlib.h>

typedef struct {
  char *data;
  int size;
  int capacity;
} vector;

void init_vector(vector *vec) {
  vec->size = 0;
  vec->capacity = 1;
  vec->data = (char *)malloc(vec->capacity * sizeof(char));
}
void resize_vector(vector *vec) {
  vec->capacity *= 1.25;
  vec->data = (char *)realloc(vec->data, vec->capacity * sizeof(char));
}
void add_element(vector *vec, char value) {
  if (vec->size == vec->capacity) {
    resize_vector(vec);
  }
  vec->data[vec->size] = value;
  vec->size++;
}
void free_vector(vector *vec) {
  free(vec->data);
  vec->data = NULL;
  vec->size = 0;
  vec->capacity = 0;
}
int main() {
  vector vec;
  init_vector(&vec);

  add_element(&vec, 'h');
  add_element(&vec, 'e');
  add_element(&vec, 'l');

  free_vector(&vec);
}
