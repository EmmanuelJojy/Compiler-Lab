// Version 2
// Reads character by character from file
// and stores in a 3D character array
// (includes storing token)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int state = 0, bcount = 0;
FILE *fp;

int reset() { bcount = 0; state = 0; fseek(fp, -1, SEEK_CUR); }

int isDigi(char ch) {
	if(ch >= '0' && ch <= '9') return 1;
	return 0;
}

int isIden(char ch) {
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_') return 1;
	return 0;
}

int isOper(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') return 1;
	return 0;
}

int isSymb(char ch) {
	if(ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ';' || ch == ',') return 1;
	return 0;
}

int isWhit(char ch) {
	if(ch == ' ' || ch == '\t' || ch == '\n') return 1;
	return 0;
}

int isKeyw(char *b) {
	if(!strcmp(b, "main") || !strcmp(b, "void") || !strcmp(b, "int")) return 1;
	return 0;
}

void main() {
	// Token Storage DS
	char *tokens[5][32];
	int cnt_num = 0, cnt_id = 0, cnt_key = 0, cnt_op = 0, cnt_sym = 0;
	// End ------------
	
	char buffer[128], ch;
	fp = fopen("input_1.txt", "r");
	
	while((ch = fgetc(fp)) != EOF) {
		buffer[bcount++] = ch;
		switch(state) {
			case 0:
				if(isDigi(ch)) 
					state = 1;
				if(isIden(ch)) 
					state = 2;
				if(isOper(ch))
					state = 3;
				if(isSymb(ch))
					state = 4;
				if(isWhit(ch)) 
					bcount = 0;
				break;
			case 1:
				if(!isDigi(ch)) {
					buffer[bcount - 1] = '\0';
					tokens[0][cnt_num] = malloc(sizeof(char) * 128);
					strcpy(tokens[0][cnt_num], buffer);
					cnt_num++;
					reset();
				}
				break;
			case 2:
				if(!isIden(ch) && !isDigi(ch)) {
					buffer[bcount - 1] = '\0';
					if(isKeyw(buffer)) {
						tokens[1][cnt_key] = malloc(sizeof(char) * 128);
						strcpy(tokens[1][cnt_key], buffer);
						cnt_key++;
					}
					else {
						tokens[2][cnt_id] = malloc(sizeof(char) * 128);
						strcpy(tokens[2][cnt_id], buffer);
						cnt_id++;
					}
					reset();
				}
				break;
			case 3:
				if(ch == '/' && buffer[bcount - 2] == '/') 
					state = 5;
				if(!isOper(ch)) {
					buffer[bcount - 1] = '\0';
					tokens[3][cnt_op] = malloc(sizeof(char) * 128);
					strcpy(tokens[3][cnt_op], buffer);
					cnt_op++;
					reset();
				}
				break;
			case 4:
				buffer[bcount - 1] = '\0';
				tokens[4][cnt_sym] = malloc(sizeof(char) * 128);
				strcpy(tokens[4][cnt_sym], buffer);
				cnt_sym++;
				reset();
				break;
			case 5:
				if(ch == '\n') {
					bcount = 0; 
					state = 0; 
					break;
				}
		}
	}
	fclose(fp);
	
	// Token Printing
	int i;
	printf("\nNumber:      [");
	for(i = 0; i < cnt_num; i++) printf("'%s' ", tokens[0][i]);
	printf("]\nKeyWord:     [");
	for(i = 0; i < cnt_key; i++) printf("'%s' ", tokens[1][i]);
	printf("]\nIdentifier:  [");
	for(i = 0; i < cnt_id; i++) printf("'%s' ", tokens[2][i]);
	printf("]\nOperators:   [");
	for(i = 0; i < cnt_op; i++) printf("'%s' ", tokens[3][i]);
	printf("]\nSymbols:     [");
	for(i = 0; i < cnt_sym; i++) printf("'%s' ", tokens[4][i]);
	printf("]\n\n");	
}