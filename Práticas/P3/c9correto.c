#include <stdlib.h>

void f(void) {
    int* x = malloc(10 * sizeof(int));
    x[9] = 0; //correcao
    free(x);
}

int main(void) {
    f();
    return 0;
}