#include <stdlib.h>
#include <string.h>
#include "parse_func.h"
#include "structs.h"

node *parser(char *str) {
    no_space(&str);
    int it = 0;
    node *list = NULL;
    int flag = 0;
    while (!flag && str[it] != '\0') {
        node *tmp = NULL;
        if ((tmp = get_op(&(str[it]), &it))) {
            list = add_end(list, tmp);
            destroy(tmp);
        } else if ((tmp = get_os_op(&str[it], &it))) {
            list = add_end(list, tmp);
            destroy(tmp);
        } else if ((tmp = get_num(&(str[it]), &it))) {
            list = add_end(list, tmp);
            destroy(tmp);
        } else {
            flag = 1;
        }
    }
    free(str);
    return list;
}

char *no_space(char **str) {
    int i, j;
    int n = strlen(*str) + 1;
    char *dest = calloc(n, sizeof(char));
    for (i = j = 0; *str && (*str)[i] != '\0'; i++)
        if ((*str)[i] != ' ')
            dest[j++] = (*str)[i];
    dest[j] = '\0';
    *str = dest;
    return (*str);
}

node *get_num(char *str, int *iterator) {
    double num;
    int i;
    char *ptr;
    node *res = calloc(1, sizeof(node));
    num = strtod(str, &ptr);
    i = (int) (ptr - str);
    if (i != 0) {
        res->num = num;
        res->type = NUMS;
        *iterator += i;
    } else if (*str == 'x') {
        int it;
        node *tmp1 = NULL, *tmp2 = NULL;
        if (str[1] == '\0' || (tmp1 = get_op(&str[1], &it))
            || (tmp2 = get_os_op(&str[1], &it))) {
            ++i;
            *iterator += i;
            res->elem = "x";
            res->type = VAR;
            destroy(tmp1);
            destroy(tmp2);
        } else {
            destroy(tmp1);
            destroy(tmp2);
            free(res);
            res = NULL;
        }
    } else {
        free(res);
        res = NULL;
    }
    return res;
}

node *get_op(char *str, int *iterator) {
    int i = 0;
    node *tmp_list = calloc(1, sizeof(node));
    if (strstr(str, "sin(") == str) {
        tmp_list->elem = "sin";
        tmp_list->type = UNARY;
        i += 3;
    } else if (strstr(str, "sqrt(") == str) {
        tmp_list->elem = "sqrt";
        tmp_list->type = UNARY;
        i += 4;
    } else if (strstr(str, "cos(") == str) {
        tmp_list->elem = "cos";
        tmp_list->type = UNARY;
        i += 3;
    } else if (strstr(str, "tan(") == str) {
        tmp_list->elem = "tan";
        tmp_list->type = UNARY;
        i += 3;
    } else if (strstr(str, "ctg(") == str) {
        tmp_list->elem = "ctg";
        tmp_list->type = UNARY;
        i += 3;
    } else if (strstr(str, "ln(") == str) {
        tmp_list->elem = "ln";
        tmp_list->type = UNARY;
        i += 2;
    } else {
        free(tmp_list);
        tmp_list = NULL;
    }
    if (tmp_list) *iterator += i;
    return tmp_list;
}

node *get_os_op(char *str, int *iterator) {
    int i = 0;
    node *tmp_list = calloc(1, sizeof(node));
    if (strchr(str, '+') == str) {
        tmp_list->elem = "+";
        tmp_list->type = PLUS_MIN;
        ++i;
    } else if (strchr(str, '-') == str) {
        if (*iterator == 0 || str[-1] == '+' || str[-1] == '-' || str[-1] == '*' || str[-1] == '/') {
            tmp_list->elem = "~";
            tmp_list->type = PLUS_MIN;
        } else {
            tmp_list->elem = "-";
            tmp_list->type = PLUS_MIN;
        }
        ++i;
    } else if (strchr(str, '*') == str) {
        tmp_list->elem = "*";
        tmp_list->type = MUL_DIV;
        ++i;
    } else if (strchr(str, '/') == str) {
        tmp_list->elem = "/";
        tmp_list->type = MUL_DIV;
        ++i;
    } else if (strchr(str, '(') == str) {
        tmp_list->elem = "(";
        tmp_list->type = BRACKETS;
        ++i;
    } else if (strchr(str, ')') == str) {
        tmp_list->elem = ")";
        tmp_list->type = BRACKETS;
        ++i;
    } else {
        free(tmp_list);
        tmp_list = NULL;
    }
    if (tmp_list) *iterator += i;
    return tmp_list;
}
