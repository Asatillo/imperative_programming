#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "rle.h"



int main(int argc, char *argv[]){
    char *text = malloc(sizeof(char) * 256);
    printf("Enter text: ");
    scanf("%s", text);
    for (size_t i = 0; i < strlen(text); i++){
        if((int)text[i] > 122 || (int)text[i] < 97){
            printf("Bad input\n");
            return 0;
        }
    }
    printf("input: %s\n", text);

    printf("output: ");
    struct Encoded *encoded = encode(text);
    for(int i = 0; i < encoded->length; i++){
        printf("%d%c",  encoded->pairs[i].count, encoded->pairs[i].character);
    }
    char *decoded = decode(encoded);
    printf(" -> %s\n", decoded);
    
    free(encoded->pairs);
    encoded->pairs = NULL;

    free(encoded);
    encoded = NULL;
    
    free(text);
    text = NULL;

    free(decoded);
    decoded = NULL;

    return 0;
}