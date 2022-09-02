#include "calc.h"
#include <math.h>

double op_result(const char *op, node *f, node *s) {
    double result = 0;
    double first_num = f->num;
    double second_num = s->num;
    if (op[0] == '+')
        result += first_num + second_num;
    else if (op[0] == '-')
        result += (second_num - first_num);
    else if (op[0] == '*')
        result += (first_num * second_num);
    else if (op[0] == '/')
        result += (second_num / first_num);
    return result;
}

double func_result(struct node *current, node lek) {
    double res = 0;
    if (strcmp(current->elem, "sin") == 0)
        res += sin(lek.num);
    else if (strcmp(current->elem, "sqrt") == 0)
        res += sqrt(lek.num);
    else if (strcmp(current->elem, "cos") == 0)
        res += cos(lek.num);
    else if (strcmp(current->elem, "tan") == 0)
        res += tan(lek.num);
    else if (strcmp(current->elem, "ctg") == 0)
        res += cos(lek.num) / sin(lek.num);
    else if (strcmp(current->elem, "ln") == 0)
        res += log(lek.num);
    else if (strcmp(current->elem, "~") == 0)
        res -= lek.num;
    return res;
}

double calc(node *list, double val) {
    double result = 0;
    if (list->type) {
        int is_result = 0;
        node *current_node = list;
        struct stack_op *current_stack = NULL;
        while (current_node != NULL) {
            int type = current_node->type;
            (current_node->elem && current_node->elem[0] == 'x') ? current_node->num = val : 0;
            if (type == NUMS || type == VAR) {
                current_stack = push(&current_stack, current_node);
            } else if (type == PLUS_MIN || type == MUL_DIV) {
                node first = *(pop(&current_stack));
                node second = {result, "", 0, NULL};
                if (!is_result) {
                    second = *(pop(&current_stack));
                    is_result = 1;
                }
                result = op_result(current_node->elem, &first, &second);
            } else if (type == UNARY) {
                node first = {0, "", 0, NULL};
                if (!is_result) {
                    first = *(pop(&current_stack));
                    is_result = 1;
                }
                result += func_result(current_node, first);
            }
            current_node = current_node->next_node;
        }
        free(current_stack);
    }
    return result;
}
