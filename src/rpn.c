#include "rpn.h"

node *to_pol(node *inp) {
    node *res = NULL;
    struct stack_op *stack = NULL;
    while (inp) {
        if (inp->type == NUMS || inp->type == VAR) {
            res = add_end(res, inp);
        } else if (inp->elem && inp->elem[0] == '(') {
            stack = push(&stack, inp);
        } else if (inp->elem && strcmp(inp->elem, ")") == 0 && stack) {
            node *leks = pop(&stack);
            while (leks && leks->elem && leks->elem[0] != '(') {
                res = add_end(res, leks);
                leks = pop(&stack);
            }
            destroy(leks);
        } else {
            while (stack && stack->type >= inp->type && stack->type != BRACKETS) {
                node *to_pop = pop(&stack);
                res = add_end(res, to_pop);
            }
            push(&stack, inp);
        }
        inp = inp->next_node;
    }
    node *op = pop(&stack);
    while (stack) {
        res = add_end(res, op);
        op = pop(&stack);
    }
    res = add_end(res, op);
    destroy(op);
    return res;
}
