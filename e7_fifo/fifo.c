#include <stdio.h>

#define max_tc 20 // MAXIMUM TRANSITION COUNT
#define max_tl 10 // MAXIMUM TRANSITION LENGTH
#define max_nt 10 // MAXIMUM ALLOWED NON TERMINAL
#define max_te 10 // MAXIMUM ALLOWED TERMINAL

char trans[max_tc][max_tl];
int trcnt = -1;

int first[max_nt][max_te];
int follow[max_nt][max_te];

char nonterm[max_nt];
int ntcnt = 0;

char term[max_te];
int tecnt;

int isNonTerminal(char ch) {
	return (ch >= 'A' && ch <='Z') ? 1 : 0;
}

int mapSymbol(char ch) {
	if(isNonTerminal(ch)) {
		for(int i = 0; i < ntcnt; i++) 
			if(nonterm[i] == ch)
				return i;
		nonterm[ntcnt++] = ch;
		return ntcnt - 1;
	}
	else {
		for(int i = 0; i < tecnt; i++) 
			if(term[i] == ch)
				return i;
		term[tecnt++] = ch;
		return tecnt - 1;
	}
}

void analyze(FILE *fp) {
	char s[32], left;
	int i;
	while(fscanf(fp, "%s", s) != EOF) {
		int tlcnt = 0;
		mapSymbol(s[0]);
		for(i = 1; i < 32 && s[i] != '\0'; i++) {
			if(s[i] == '=' || s[i] == '|') {
				if(i == '|') 
					trans[trcnt][tlcnt++] = '\0';
				trcnt++; tlcnt = 0;
				trans[trcnt][tlcnt++] = s[0];
				trans[trcnt][tlcnt++] = '=';
				continue;
			} 
			mapSymbol(s[i]);
			trans[trcnt][tlcnt++] = s[i];
		}
		trans[trcnt][tlcnt++] = '\0';
	}
	trcnt++;
	
	printf("Transitions Read: (%d)\n", trcnt + 1);
	for(i = 0; i < trcnt; i++) printf("  %s\n", trans[i]);
	
	printf("Non-Terminals Encountered: (%d)\n  ", ntcnt);
	for(i = 0; i < ntcnt; i++) printf("%c ", nonterm[i]);
	
	printf("\nTerminals Encountered: (%d)\n  ", ntcnt);
	for(i = 0; i < tecnt; i++) printf("%c ", term[i]);
	printf("\n\n");
}

void find_first(char T, char curr) {
	int i;
	for(i = 0; i < trcnt; i++) {
		if(trans[i][0] == curr) {
			if(isNonTerminal(trans[i][2]))
				find_first(T, trans[i][2]);
			else
				first[mapSymbol(T)][mapSymbol(trans[i][2])] = 1;
		}
	}				
}

void copy_follow(char T, char fo) {
	for(int i = 0; i < tecnt; i++) {
		if(follow[mapSymbol(fo)][i] == 1) {
			follow[mapSymbol(T)][i] = 1;
		}
	}
}

int copy_first(char T, char fi) {
	int flag = 0;
	for(int i = 0; i < tecnt; i++) {
		if(first[mapSymbol(fi)][i] == 1) {
			follow[mapSymbol(T)][i] = 1;
			if(term[i] == '#') 
				flag = 1;
		}
	}
	return flag;
}
	
void find_follow_rep(char T, int i, int j) {
	int flag = copy_first(T, trans[i][j]);
	if(flag && trans[i][j + 1] != '\0') {
		find_follow_rep(T, i, j + 1);
	}
	else {
		copy_follow(T, trans[i][j]);
	}
}

void find_follow(char T, char curr) {
	int i, j;
	for(i = 0; i < trcnt; i++) {
		for(j = 2; j < max_tl && trans[i][j] != '\0'; j++) {
			char next = trans[i][j + 1];
			if(trans[i][j] == curr) {
				if(isNonTerminal(next) && next != trans[i][0]) {
					find_follow_rep(T, i, j + 1);
				}
				else if(next == '\0') {
					copy_follow(T, trans[i][0]);
				}
				else if(!isNonTerminal(next))
				{
					follow[mapSymbol(T)][mapSymbol(next)] = 1;
				}
			}
		}
	}
}			

void main() {
	FILE *fp = fopen("gram.txt", "r");
	analyze(fp);
	fclose(fp);
	
	int i, j;
	for(i = 0; i < ntcnt; i++){
		char T = nonterm[i];
		find_first(T, T);
		printf("First(%c)  = { ", T);
		int index = mapSymbol(T);
		for(j = 0; j < tecnt; j++)
			if(first[index][j])
				printf("%c, ", term[j]);
		printf("}\n");
	}
	
	printf("\n");
	follow[mapSymbol(trans[0][0])][mapSymbol('$')] = 1;
	char prev = '!';
	for(i = 0; i < trcnt; i++){
		char T = trans[i][0];
		if(T == prev) 
			continue;
		find_follow(T, T);
		printf("Follow(%c) = { ", T);
		int index = mapSymbol(T);
		for(j = 0; j < tecnt; j++) {
			if(term[j] == '#')
				continue;
			if(follow[index][j])
				printf("%c, ", term[j]);
		}
		printf("}\n");
		prev = T;
	}
}
