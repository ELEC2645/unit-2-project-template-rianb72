#ifndef FUNCS_H
#define FUNCS_H

void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);

double evaluate(const char *expr, double x);
double bisection(const char *expr, double a, double b, double tol, int maxIter);
double false_position(const char *expr, double a, double b, double tol, int max_iterations);
double newton_raphson(const char *expr, double x0, double tol, double max_iterations);
double secant(const char *expr, double x0, double x1, double tol, double max_iterations);

#endif