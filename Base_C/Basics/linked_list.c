#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
typedef struct node {
  int val;
  struct node * next;
} node_t;

void print_list(node_t * head) {
  node_t * current = head;

  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

void push(node_t * head, int val) {
  node_t * current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = (node_t *) malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;
}

void push_start(node_t ** head, int val) {
  node_t * new_node;
  new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

int pop(node_t ** head) {
  int retval = -1;
  node_t * next_node = NULL;

  if (*head == NULL) {
    return -1;
  }

  next_node = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = next_node;
  return retval;
}

int remove_last(node_t * head) {
  int retval = 0;

  if (head->next == NULL) {
    retval = head->val;
    free(head);
    return retval;
  }

  node_t * current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }

  retval = current->next->val;
  free(current->next);
  current->next = NULL;
  return retval;
}
int main() {
  node_t * head = NULL;
  head = (node_t *) malloc(sizeof(node_t));
  if (head == NULL) {
    return 1;
  }  

  head->val = 1;
  head->next = NULL;

  head->next = (node_t *) malloc(sizeof(node_t));
  head->next->val = 2;
  head->next->next = NULL;
}
