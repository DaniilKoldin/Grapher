#ifndef SRC_STRUCTS_H_
#define SRC_STRUCTS_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMS 1
#define VAR 2
#define PLUS_MIN 3
#define MUL_DIV 4
#define UNARY 5
#define BRACKETS 6
#define ERROR -1

typedef struct node {
    double num;
    char *elem;
    int type;
    struct node *next_node;
} node;

struct node *init(node*);

struct node *add_end(struct node *root, node*);

void destroy(struct node *root);

struct stack_op {
    char *info;
    double num;
    int type;
    struct stack_op *prev;
};

node *pop(struct stack_op **top);

struct stack_op *push(struct stack_op **top, node* elem);

struct stack_op *init_st(node * elem);

void destroy_st(struct stack_op *top);

#endif      //  SRC_STRUCTS_H_
