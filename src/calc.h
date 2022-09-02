#ifndef SRC_CALC_H_
#define SRC_CALC_H_
#include "structs.h"
#include "rpn.h"
double calc(node *list, double val);

double op_result(const char * op, node *f, node *s);
double func_result(struct node *current, node lek);


#endif      //  SRC_CALC_H_
