#include "list/slist_node.h"
#include <stdlib.h>
#include <assert.h>

slist_node* get_slist_node() {
  static int value = 0;
  slist_node* node = (slist_node*)malloc(sizeof(slist_node));
  if (node) {
    node->value = ++value;
  }
  return node;
}
void put_slist_node(slist_node* node) {
  free(node);
}
void insert_after_slist_node(slist_node* prev,
    slist_node* next) {
  assert(prev != NULL);
  assert(next != NULL);
  next->next = prev->next;
  prev->next = next;
}
slist_node* reverse_slist(slist_node* head,
		slist_node* end_node) {
   if (!head || head->next == end_node) {
      return head;
    }
    slist_node* next = NULL;
    slist_node* node = head->next;
    head->next = end_node;
    while (node != end_node) {
      next = node->next;
      node->next = head;
      head = node;
      node = next;
    }
    return head;
}
slist_node* reverse_slist_recursion(slist_node* head,
		slist_node* end_node) {
    if (!head || head->next == end_node) {
      return head;
    }
    slist_node* next_node = head->next;
    slist_node* new_head = reverse_slist_recursion(next_node,
		    end_node);
    next_node->next = head;
    head->next = new_head;
    return new_head;
}
void print_slist(const slist_node* head,
		const slist_node* end_node,
    slist_node_visit fn) {
  if (!head) {
    return;
  }
  const slist_node* node = head;
  do {
    fn(node);
    node = node->next;
  } while (node != end_node);
}
void print_slist_recursion(const slist_node* curr_node,
		const slist_node* end_node,
    slist_node_visit fn) {
  if (curr_node->next != end_node) {
    fn(curr_node);
    curr_node = curr_node->next;
  }
}
