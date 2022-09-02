#ifndef SRC_PARSE_FUNC_H_
#define SRC_PARSE_FUNC_H_

#include "structs.h"

char *no_space(char **str);

node *get_num(char *str, int *iterator);

node *get_op(char *str, int *iterator);

node *get_os_op(char *str, int *iterator);

node *parser(char *str);

#endif          //   SRC_PARSE_FUNC_H_
