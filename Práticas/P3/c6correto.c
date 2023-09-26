#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct _List {
    int32_t* data;
    int32_t length;
};
typedef struct _List List;

List* resizeArray(List* array) {
    int32_t* dPtr = array->data;
    dPtr = realloc(dPtr, 15 * sizeof(int32_t)); //doesn't update array->data
    array->length = 10;

    if (dPtr != NULL) {
        array->data = dPtr;

        for (int i = 0; i < array->length; i++) {
            array->data[i] = i;
        }
    }
    
    return array;
}

int main() {
    List* array = calloc(1, sizeof(List));
    array->data = calloc(10, sizeof(int32_t));
    array->length = 5;

    for (int i = 0; i < array->length; i++) {
        array->data[i] = i;
        printf("%d", array->data[i]);
    }
    
    printf("\n");
    array = resizeArray(array);

    for (int i = 0; i < array->length; i++) {
        array->data[i] = i;
        printf("%d", array->data[i]);
    }
    
    printf("\n");

    free(array->data);
    free(array);
    return 0;
}
