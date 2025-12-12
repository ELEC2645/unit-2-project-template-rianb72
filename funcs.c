#include <stdio.h>
#include "funcs.h"
#include "tinyexpr.h"

void menu_item_1(void) {
    printf("\n>> Menu 1\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 1 */
    te_variable vars[] = {{"x", &x}};
    te_expr *e = te_compile(expr, vars, 1, NULL);
    double result = te_eval(e);
    te_free(e);
    return result;
    int iter_count = 0, max_iter_count;
    float mid_point, start, end, error, root;

}

void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
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