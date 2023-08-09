#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char* argv[]){

    int A[] = {1,2,3,4,5,6,7,8,9, 10};
    int B[] = {10,9,8,7,6,5,4,3,2,1};
    int C[] = {3,1,6,7,11,2,4,8,5,9};
    cartesian1(A, B);
    cartesian1(A, C);
    cartesian1(B, C);

    int size_a, size_b;
    printf("\n Write the size of the first array => ");
    scanf("%d", &size_a);
    printf("\n Write the size of the second array => ");
    scanf("%d", &size_b);

    int *dinamic_A = malloc(sizeof(int)*size_a);
    if(dinamic_A == NULL){
        printf("Error allocating memmory!");
        return 1;
    }
    for(int i=0;i<size_a;i++){
        printf("Array#1 element #%d: ", i+1);
        scanf("%d", &dinamic_A[i]);
    }

    int *dinamic_B = malloc(sizeof(int)*size_b);
    if(dinamic_B == NULL){
        printf("Error allocating memmory!");
        return 1;
    }
    for(int i=0;i<size_b;i++){
        printf("Array#2 element #%d: ", i+1);
        scanf("%d", &dinamic_B[i]);
    }

    struct pair *values = malloc(sizeof(struct pair)*size_a*size_b);
    if(values == NULL){
        printf("Error allocating memmory!");
        return 1;
    }

    values = cartesian2(dinamic_A, dinamic_B, size_a, size_b);
    
    FILE* f;
    f = fopen("out.txt", "w");
    if(f == NULL){
        printf("Error reading file!");
        exit(-1);
    }
    fprintf(f, "{");
    for(int i=0;i<size_a*size_b;i++){
        fprintf(f, "(%d, %d), ", values[i].a, values[i].b);
    }
    fprintf(f, "}");
    fclose(f);

    struct pair *values2 = malloc(sizeof(struct pair)*size_a*size_b);
    if(values2 == NULL){
        printf("Error allocating memmory!");
        return 1;
    }
    int new_size;
    values2 = cartesian3(dinamic_A, dinamic_B, size_a, size_b, &new_size);
    for(int i=0;i<new_size;i++){
        // printf("(%d, %d), ", values2[i].a, values2[i].b);
    }

    free(values);
    free(values2);
    free(dinamic_A);
    free(dinamic_B);
    
    values = NULL;
    values2 = NULL;
    dinamic_A = NULL;
    dinamic_B = NULL;
    
    return 0;
}

