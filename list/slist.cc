#include "list/slist.h"
#include <stdio.h>

slist::slist() {
  head_.next = &head_;
  head_.value = 0;
}
slist::~slist() {
  slist_node* node = head_.next;
  slist_node* next = NULL;
  while (node != &head_) {
    slist_node* next = node->next;
    put_slist_node(node);
    node = next;
  }
}
void slist::push(slist_node* node) {
  if (!node) {
    return;
  }
  insert_after_slist_node(&head_, node);
  ++head_.value;
}
slist_node* slist::pop() {
  slist_node* node = head_.next;
  head_.next = node->next;
  return node;
}
int slist::print_slist(const slist_node* node) {
  static int count = 0;
  if (count == 10) {
    putchar('\n');
    count = 0;
  }
  ++count;
  return printf("%d\t", node->value);
}
void slist::print() {
  // not 
  ::print_slist(&head_, &head_, &slist::print_slist);
}
size_t slist::size() {
  return head_.value;
}
