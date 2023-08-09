#include "rle.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct Encoded *encode(char *string){
    struct Encoded *encoded = malloc(sizeof(struct Encoded));
    encoded->length = 0;
    encoded->pairs = malloc(sizeof(struct Pair));
    char current = string[0];
    int count = 1;
    for(int i = 1; i < strlen(string); i++){
        if(string[i] == current){
            count++;
        }
        else{
            encoded->pairs[encoded->length].character = current;
            encoded->pairs[encoded->length].count = count;
            encoded->length++;
            encoded->pairs = realloc(encoded->pairs, sizeof(struct Pair) * (encoded->length + 1));
            current = string[i];
            count = 1;
        }
        if(i == strlen(string) - 1){
            encoded->pairs[encoded->length].character = current;
            encoded->pairs[encoded->length].count = count;
            encoded->length++;
        }
    }

    return encoded;
}

char *decode(struct Encoded *encoded){
    int length = 0;
    for(int i=0;i<encoded->length;i++){
        length += encoded->pairs[i].count;
    }
    char *decoded = malloc(sizeof(char) * length);
    int current = 0;
    for(int i = 0; i < encoded->length; i++){
        for(int j = 0; j < encoded->pairs[i].count; j++){
            decoded[current++] = encoded->pairs[i].character;
        }
    }
    decoded[length] = '\0';
    return decoded;
}