#include <stdio.h>
#include "funcs.h"
#include "tinyexpr.h"
#include <math.h>

void menu_item_1(void) {
    printf("\nBisection Method:\n");

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
        printf("\nError: invalid expression at position %d\n", err);
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
        printf("\nError: f(a) and f(b) must have opposite signs.\n");
        return NAN;
    }

    for (int i = 0; i < max_iterations; i++) { // bisection formula
        double m = (a + b) / 2.0;
        double fm = evaluate(expr, m);

        if (fabs(fm) < tol || fabs(b - a) < tol)
            return m;

        if (fa * fm < 0) { // Update interval
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
    printf("\nFalse Position Method:\n");
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
        printf("\nError: f(a) and f(b) must have opposite signs.\n");
        return NAN;
    }

    for (int i = 0; i < max_iterations; i++) {
        double m = (a * fb - b * fa) / (fb - fa);  // False position formula
        double fm = evaluate(expr, m);

        if (fabs(fm) < tol)
            return m;

        if (fa * fm < 0) { // Update interval
            b = m;
            fb = fm;
        } else {
            a = m;
            fa = fm;
        }
    }
}

void menu_item_3(void) {
    printf("\nNewton-Raphson Method:\n");
    char expr[100];
    int max_iterations;
    double guess, tol, root;

    printf("Enter f(x): ");
    scanf("%99s", expr);

    printf("\nEnter initial guess: ");
    scanf("%lf", &guess);

    printf("\nEnter the maximum number of iterations allowed: ");
    scanf("%d", &max_iterations);

    printf("\nInput the allowed error tolerance: ");
    scanf("%lf", &tol);

    root = newton_raphson(expr, guess, tol, max_iterations);

    if (!isnan(root)) {
        printf("\nApproximate root: %.10f\n", root);
        printf("f(root) = %.10f\n", evaluate(expr, root));
    }
}

double newton_raphson(const char *expr, double x0, double tol, double max_iterations) {
    double h = 1e-6; 
    for (int i = 0; i < max_iterations; i++) {
        double fx = evaluate(expr, x0);
        double dfx = (evaluate(expr, x0 + h) - fx) / h; // finding the derivative

        if (fabs(dfx) < 1e-12) {
            printf("\nError: derivative is too small (near zero) or invalid input. Newton-Raphson fails.\n");
            return NAN;
        }

        double x1 = x0 - fx / dfx;

        if (fabs(x1 - x0) < tol) {
            return x1;  // result found
        }

        x0 = x1;
    }

    printf("\nError: method did not converge within max iterations.\n");
    return NAN;
}

void menu_item_4(void) {
    printf("\nSecant Method:\n");

    char expr[100];
    double x0, x1, tol, root;
    int max_iterations;

    printf("Enter f(x): ");
    scanf("%99s", expr);

    printf("\nEnter first initial guess (x0): ");
    scanf("%lf", &x0);

    printf("\nEnter second initial guess (x1): ");
    scanf("%lf", &x1);

    printf("\nEnter maximum number of iterations: ");
    scanf("%d", &max_iterations);

    printf("\nEnter error tolerance: ");
    scanf("%lf", &tol);

    root = secant(expr, x0, x1, tol, max_iterations);

    if (!isnan(root)) {
        printf("\nApproximate root: %.10f\n", root);
        printf("f(root) = %.10f\n", evaluate(expr, root));
    }
}

double secant(const char *expr, double x0, double x1, double tol, double max_iterations) {
    double f0 = evaluate(expr, x0);
    double f1 = evaluate(expr, x1);

    for (int i = 0; i < max_iterations; i++) {
        if (fabs(f1 - f0) < 1e-12) {
            printf("\nError: denominator too small or invalid input, secant method fails.\n");
            return NAN;
        }

        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        double f2 = evaluate(expr, x2);

        if (fabs(x2 - x1) < tol || fabs(f2) < tol) {
            return x2;  // result found
        }

        x0 = x1; // move forward
        f0 = f1;
        x1 = x2;
        f1 = f2;
    }

    printf("\nError: Secant method did not converge within max iterations.\n");
    return NAN;
}