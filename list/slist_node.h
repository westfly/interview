#ifndef LIST_SLIST_NODE_H_
#define LIST_SLIST_NODE_H_
typedef struct slist_node {
  struct slist_node* next;
  int value;
} slist_node;
#ifdef __cplusplus
extern "C" {
#endif 
typedef int (*slist_node_visit)(const slist_node* node);
typedef int (*slist_node_cmp)(const slist_node* first,
		const slist_node* last);
// useful function
extern slist_node* get_slist_node();
extern void put_slist_node(slist_node* node);
extern void insert_after_slist_node(slist_node* prev,
    slist_node* next);
extern slist_node* reverse_slist(slist_node* head,
		slist_node* end_condition);
extern slist_node* reverse_slist_recursion(slist_node* head,
		slist_node* end_condition);
void print_slist(const slist_node* curr_node,
    const slist_node* end_node,
    slist_node_visit fn);
void print_slist_recursion(const slist_node* curr_node,
    const slist_node* end_node,
    slist_node_visit fn);

#ifdef __cplusplus
}
#endif 
#endif  // LIST_SLIST_NODE_H_
