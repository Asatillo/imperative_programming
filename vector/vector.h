#ifndef VECTOR_H_DEFINED
#define vecTOR_H_DEFINED

#define VECTOR_TYPE int

typedef struct {
    unsigned int capacity;
    unsigned int size;
    VECTOR_TYPE* data;
} Vector;

int initialize(Vector* v, int capacity);
void dispose(Vector* v);
int append(Vector* v, VECTOR_TYPE e);
int retrieve(Vector* v, int i);
int insert(Vector* v, int i, VECTOR_TYPE e);
int erase(Vector* v, int i);
int set_capacity(Vector* v, unsigned int c);
void safe_append(Vector* v, VECTOR_TYPE e);
void safe_insert(Vector* v, int i, VECTOR_TYPE e);

#endif