#include "list/slist.h"
#include <stdio.h>
int main(int argc, char * argv[]) {
  slist list;
  int n = 10;  
  while (n--) {
    slist_node* node = get_slist_node();
    list.push(node);
  }
  list.print();
  printf("before\n");
  list.reverse();
  list.print();
  printf("while\n");
  return 0;
}
