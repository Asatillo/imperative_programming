#ifndef RLE_H
#define RLE_H

struct Pair{
    char character;
    int count;
};

struct Encoded{
    int length;
    struct Pair *pairs; 
};

struct Encoded *encode(char *string);
char *decode(struct Encoded *encoded);

#endif /*RLE_H*/