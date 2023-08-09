#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_functions.h"

int main(int argc, char *argv[]){
	if (argc < 2) {
		char **words;
        int maxsize = 8;
        words = malloc(maxsize * sizeof(char *));
        char line[1024] = {0};
        unsigned int line_count = 0;

        while (fgets(line, 1024, stdin)!=NULL){
            if(line_count >= maxsize){
                maxsize*=2;
                words= realloc(words,maxsize*sizeof(char*));
				if(words==NULL){
					printf("Memory allocation failed!");
				}
            }
 
            words[line_count] = malloc(1024 * sizeof(char));
            if (words == NULL){
                printf("Memory allocation failed!");
            }
            strcpy(words[line_count], line);
            line_count++;
            if  (strlen(line) != 0 && line[strlen(line)-1] != '\n') printf("\n");
        }
        for (int i = line_count - 1; i >= 0; i--){
            reverse2(words[i]);
            printf("%d %s", i+1, words[i]);
            free(words[i]);
        }
        free(words);
	} else {
		int line_count;	
		for (int i=0;i<(argc-1);i++){
			char *filename = argv[i+1];
			FILE *fp = fopen(filename,"r");
			if(fp==NULL){
				printf("File opening unsuccessful!");
				return 0;
			}
			fclose(fp);

			line_count = countlines(filename);
			reverse(filename, line_count);
			printf("\n");
		}
	} 
	return 0;
}

