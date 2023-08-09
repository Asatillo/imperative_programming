#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char* argv[]){
    Circle c1 = {1, 2, 3};
    Square s1 = {2, 0, 11};
    Square s2 = {2, 0, 2};

    printf("%d ", isInside(&s1, &c1));
    printf("%d ", isInside(&s2, &c1));
    return 0;
}

