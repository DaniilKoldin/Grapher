#include "structs.h"

struct stack_op *init_st(node *elem) {
    struct stack_op *root = calloc(1, sizeof(struct stack_op));
    root->info = elem->elem;
    root->num = elem->num;
    root->type = elem->type;
    return root;
}

struct stack_op *push(struct stack_op **top, node *elem) {
    if (*top == NULL) {
        *top = init_st(elem);
    } else {
        struct stack_op *new_el = init_st(elem);
        new_el->prev = *top;
        *top = new_el;
    }
    return *top;
}

node *pop(struct stack_op **top) {
    node *res = NULL;
    if (top && *top) {
        res = calloc(1, sizeof(node));
        struct stack_op *tmp = *top;
        (*top) = (*top)->prev;
        res->elem = tmp->info;
        res->num = tmp->num;
        res->type = tmp->type;
        free(tmp);
    }
    return res;
}
// Can be changed

struct node *init(node *elem) {
    struct node *root = calloc(1, sizeof(struct node));
    root->elem = elem->elem;
    root->num = elem->num;
    root->type = elem->type;
    return root;
}

struct node *add_end(node *root, node *elem) {
    if (!root) {
        root = init(elem);
    } else {
        struct node *new = NULL;
        new = init(elem);
        struct node *cur = root;
        while (cur->next_node != NULL) {
            cur = cur->next_node;
        }
        cur->next_node = new;
    }
    return root;
}


void destroy(struct node *root) {
    struct node *ptr = root;
    while (ptr) {
        root = root->next_node;
        free(ptr);
        ptr = root;
    }
}

