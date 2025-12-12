#include <stdio.h>
#include "funcs.h"
#include "tinyexpr.h"
#include <math.h>

void menu_item_1(void) {
    printf("\n>> Bisection Method:\n");

    char expr[100];
    int max_iterations;
    double a, b, tol, root;

    printf("Enter f(x): ");
    scanf("%99s", expr);

    printf("\nEnter the starting point(a): ");
    scanf("%lf", &a);

    printf("\nEnter the ending point(b): ");
    scanf("%lf", &b);

    printf("\nEnter the maximum number of iterations allowed: ");
    scanf("%d", &max_iterations);

    printf("\nInput the allowed error tolerance: ");
    scanf("%lf", &tol);

    root = bisection(expr, a, b, tol, max_iterations);

    if (!isnan(root)) {
        printf("\nApproximate root: %.10f\n", root);
        printf("f(root) = %.10f\n", evaluate(expr, root));
    }
}

double evaluate(const char *expr, double x) { //Error handling and evaluating expression using tinyexpr
    te_variable vars[] = { {"x", &x} };
    int err;
    te_expr *e = te_compile(expr, vars, 1, &err);

    if (!e) {
        printf("Error: invalid expression at position %d\n", err);
        return NAN;
    }

    double result = te_eval(e);
    te_free(e);

    return result;
}

double bisection(const char *expr, double a, double b, double tol, int max_iterations) {
    double fa = evaluate(expr, a);
    double fb = evaluate(expr, b);

    if (fa * fb > 0) {
        printf("Error: f(a) and f(b) must have opposite signs.\n");
        return NAN;
    }

    for (int i = 0; i < max_iterations; i++) {
        double m = (a + b) / 2.0;
        double fm = evaluate(expr, m);

        if (fabs(fm) < tol || fabs(b - a) < tol)
            return m;

        if (fa * fm < 0) {
            b = m;
            fb = fm;
        } else {
            a = m;
            fa = fm;
        }
    }
    return (a + b) / 2.0;
}



void menu_item_2(void) {
    printf("\n>> False Position Method\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
    char expr[100];
    int max_iterations;
    double a, b, tol, root;

    printf("Enter f(x): ");
    scanf("%99s", expr);

    printf("\nEnter the starting point(a): ");
    scanf("%lf", &a);

    printf("\nEnter the ending point(b): ");
    scanf("%lf", &b);

    printf("\nEnter the maximum number of iterations allowed: ");
    scanf("%d", &max_iterations);

    printf("\nInput the allowed error tolerance: ");
    scanf("%lf", &tol);

    root = false_position(expr, a, b, tol, max_iterations);

    if (!isnan(root)) {
        printf("\nApproximate root: %.10f\n", root);
        printf("f(root) = %.10f\n", evaluate(expr, root));
    }

}

double false_position(const char *expr, double a, double b, double tol, int max_iterations) {
    double fa = evaluate(expr, a);
    double fb = evaluate(expr, b);

    if (fa * fb > 0) {
        printf("Error: f(a) and f(b) must have opposite signs.\n");
        return NAN;
    }

    for (int i = 0; i < max_iterations; i++) {

        // False position formula
        double m = (a * fb - b * fa) / (fb - fa);  
        double fm = evaluate(expr, m);

        if (fabs(fm) < tol)
            return m;

        // Update interval
        if (fa * fm < 0) {
            b = m;
            fb = fm;
        } else {
            a = m;
            fa = fm;
        }
    }
}

void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}