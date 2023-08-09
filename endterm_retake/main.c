#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

const int SIZE_SLOTS = 10;

int main(int argc, char* argv[]){
    int *slots;
    slots = calloc(SIZE_SLOTS, sizeof(int));
    if (slots == NULL) exit(-1);

    FILE* f;
    if (argc <= 1){
        char name[256];
        printf("Input the name of the file: ");
        scanf("%s", &name);
        f = fopen(name, "r");
        if(f == NULL){
            printf("Error reading file!");
            exit(-1);
        }
        // TEST
        // read(slots, 10, 1);
        // read(slots, 20, 3);
        // read(slots, 30, 7);
        // add(slots, 1, 2, 9);
        // mul(slots, 3, 1, 6);
        // print(slots, 9);
        // print(slots, 6);
    } else {
        f = fopen(argv[1], "r");
        if(f == NULL){
            printf("Error reading file!");
            exit(-1);
        }
        
    }
    char line[256];
        
        while (fgets(line, sizeof(line), f)) {
            printf("%s", line); 
            // split analyze and apply the function
        }
        fclose(f);

    free(slots);
    slots = NULL;
}

