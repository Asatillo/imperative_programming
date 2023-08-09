#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

int distance(int a,int b,int x,int y)
{
    return ((x-a)*(x-a)+(y-b)*(y-b));
}

int isInside(Square* s, Circle* c)
{
    if(((distance(s->x,s->y-(s->l)/2,c->x,c->y))>=c->r*c->r)&&
       ((distance(s->x-(s->l)/2,s->y,c->x,c->y))>=c->r*c->r)&&
       ((distance(s->x,s->y+(s->l)/2,c->x,c->y))>=c->r*c->r)&&
       ((distance(s->x+(s->l)/2,s->y,c->x,c->y))>=c->r*c->r))
    {
        return 1;
    }
    return 0;
}


Circle* areInside(Circle* circles, Square* s, int size){
    int num_circles=0;
    Circle *circles_inside = malloc(sizeof(Circle));
    if(circles_inside==NULL){
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (isInside(s, &circles[i])){
            circles_inside[num_circles++] = circles[i];
            circles_inside = realloc(circles_inside, (num_circles+1)*sizeof(Circle));
        }
    }
    size = num_circles;
    return circles_inside;
}

/*
Create a function which gets an array of circles and a color as 
parameter and returns a pointer to the smallest circle of that color from 
the array. In case there is no circle of that color in the array, then return a NULL pointer.
(10 points)

*/

void* smallestCircle(Circle* circles, Color color, int size){
    Circle *colors_ = malloc(sizeof(Circle));
    if(colors_==NULL){
        return NULL;
    }
    int colors_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (circles[i].color == color)
        {
            colors_[colors_size++] = circles[i];
            colors_ = realloc(colors_, (colors_size+1)*sizeof(Circle));
        }
        
    }

    if (colors_==0)
    {
        free(colors_);
        return NULL;
    }else{
        Circle smallest = sizeof(Circle);
        smallest = &colors_[0];
        for(int i=1;i<colors_size;i++){
            if(smallest.r<(&colors_[i].r)){
                smallest = colors_[i];
            }
        }


        free(colors_);
        return smallest;
    }
}

