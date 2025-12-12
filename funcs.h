#ifndef FUNCS_H
#define FUNCS_H

void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);

double evaluate(const char *expr, double x);
double bisection(const char *expr, double a, double b, double tol, int maxIter);

#endif