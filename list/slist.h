#ifndef LIST_SLIST_H_
#define LIST_SLIST_H_
#include "list/slist_node.h"
#include <stddef.h>
struct slist {
  slist();
  ~slist();
  void push(slist_node* node);
  slist_node* pop();
  void print();
  static int print_slist(const slist_node* node);
  size_t size();
 private:
  slist_node head_;
};
#endif  // LIST_SLIST_H_
