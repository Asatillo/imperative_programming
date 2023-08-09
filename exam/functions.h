#ifndef FUNCTIONS_DEFINED
#define FUNCTIONS_DEFINED

#define SIZE 10

struct pair{
    int a;
    int b;
};

void cartesian1(int A[], int B[]);
struct pair *cartesian2(int *A, int *B, int size_a, int size_b);
struct pair *cartesian3(int *A, int *B, int size_a, int size_b, int *new_size);

#endif