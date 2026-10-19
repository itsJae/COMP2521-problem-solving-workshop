#include <stdio.h>
#include <stdlib.h>
#include "../../adt/Stack.h"

void sortTube(Stack tube, Stack bowl) {
    while (!StackIsEmpty(tube)) {
        int *chip = StackPop(tube);
        while (!StackIsEmpty(bowl) && *(int *) StackPeek(bowl) < *chip) {
            StackPush(tube, StackPop(bowl));
        }
        StackPush(bowl, chip);
    }

    while (!StackIsEmpty(bowl)) {
        StackPush(tube, StackPop(bowl));
    }
}
