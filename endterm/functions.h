#ifndef FUNCTIONS
#define FUNCTIONS

typedef enum {
    blcak, white, red, blue, green, yellow, orange
}Color;

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int r;
    Color color;
} Circle;

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int l;
    Color data;
} Square;

int distance(int a,int b,int x,int y);
int isInside(Square* s, Circle* c);
Circle* areInside(Circle* circles, Square* s, int size);
void* smallestCircle(Circle* circles, Color color, int size);

#endif