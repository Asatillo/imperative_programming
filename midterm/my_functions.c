#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Counts lines of the file
int countlines(char *filename){
	int ch=0, lines=0;

	FILE *fp = fopen(filename,"r");
	lines++;
	while ((ch = fgetc(fp)) != EOF){
		if (ch == '\n') lines++;
	}
	fclose(fp);
	return lines;
}
// Reverse used for files, especially when file taken as an argument
void reverse(char *filename, int lines){
    FILE *fp = fopen(filename, "r");
	
	char ch, newch[1024];
    int i=0, j, COUNT=0;

    ch = getc(fp);
    while(ch != EOF){
        COUNT++;
        newch[i] = ch;
        i++;
        ch = getc(fp);
    }
    printf("%d ", lines);
    lines--;
    for(j=(COUNT-1); j>=0; j--){
        if (ch == '\n'){
            printf("%d ", lines);
            lines--;
		}
        ch = newch[j];
        printf("%c", ch);
		}
	fclose(fp); 
}

// Reverse for user input lines 
void reverse2(char *str){
	char temp, holder;
	int len = strlen(str) - 1;
	for (int i = 0; i<len/2;i++){
		temp = str[i];
        holder = (len - i - 1);
		str[i] = str[holder];
		str[holder] = temp;
	}
}