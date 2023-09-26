#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *p;
    p = malloc(128);

    for(int i = 0; i < 32; i++) {
        p[i] = i;
        printf("%d\n", p[i]);
    }
    
    free(p);
    
    return 0;
}
