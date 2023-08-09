#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"



void cartesian1(int A[], int B[]){
    int size_val =SIZE*SIZE; 
    struct pair values[size_val];
    int num = 0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            values[num].a = A[i];
            values[num].b = B[j];
            num++;
        }
    }
    printf("\n===============================\n{");
    for(int i=0;i<num;i++){
        printf("(%d, %d), ", values[i].a, values[i].b);
    }
    printf("}\n===============================\n");
    
}

struct pair *cartesian2(int *A, int *B, int size_a, int size_b){
    struct pair *values = malloc(sizeof(struct pair)*size_a*size_b);
    if(values == NULL){
        printf("Error allocating memmory!");
        return NULL;
    }

    int num = 0;
    for(int i=0;i<size_a;i++){
        for(int j=0;j<size_b;j++){
            values[num].a = A[i];
            values[num].b = B[j];
            num++;
        }
    }
    printf("\n===============================\n{");
    for(int i=0;i<num;i++){
        printf("(%d, %d), " , values[i].a, values[i].b);
    }
    printf("}\n===============================\n");
    return values;
}

struct pair *cartesian3(int *A, int *B, int size_a, int size_b, int *new_size){
    int size_val =size_a*size_b; 
    struct pair *values = malloc(sizeof(struct pair)*size_a*size_b);
    if(values == NULL){
        printf("Error allocating memmory!");
        return NULL;
    }

    values = cartesian2(A, B, size_a, size_b);
    /*get rid of duplicates*/
    return values;
}
