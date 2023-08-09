#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

int initialize(Vector* v, int capacity) {
    if (capacity < 0) return 0;
    v->capacity = capacity;
    v->size = 0;
    v->data = malloc(sizeof(VECTOR_TYPE) * capacity);
    return 1;
}

void dispose(Vector* v)
{
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int append(Vector* v, VECTOR_TYPE e)
{
    if (v->size >= v->capacity) return 0;
    v->data[v->size++] = e;
    return 1;
}

int retrieve(Vector* v, int i)
{
    return v->data[i];
}

int insert(Vector* v, int i, VECTOR_TYPE e)
{
    if (v->size >= v->capacity) return 0;
    memmove(&v->data[i+1], &v->data[i], sizeof(VECTOR_TYPE) * ((v->size++)-i));    
    v->data[i] = e;
    return 1;
}

int erase(Vector* v, int i)
{
    if (i >= v->size) return 0;
    memmove(&v->data[i], &v->data[i+1], sizeof(VECTOR_TYPE) * (--v->size)-i);
    return 1;
}

VECTOR_TYPE* realloc_move(VECTOR_TYPE* p, unsigned int oldc, unsigned int c)
{
    VECTOR_TYPE* data = malloc(sizeof(VECTOR_TYPE) * c);
    memcpy(data, p, sizeof(VECTOR_TYPE) * oldc);
    free(p);
    return data;
}

int set_capacity(Vector* v, unsigned int c)
{
    if (c <= v->capacity) return 0;
    //v->data = realloc(v->data, sizeof(VECTOR_TYPE) * (v->capacity = c));
    v->data = realloc_move(v->data, v->capacity, c);
    return 1;
}

void safe_append(Vector* v, VECTOR_TYPE e)
{
    if (v->size >= v->capacity) set_capacity(v, v->capacity * 2);
    append(v, e);
}

void safe_insert(Vector* v, int i, VECTOR_TYPE e)
{
    if (v->size >= v->capacity) set_capacity(v, v->capacity * 2);
    insert(v, i, e);
}
