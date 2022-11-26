#include <stdio.h>

#define max_tc 20 // MAXIMUM TRANSITION COUNT
#define max_tl 10 // MAXIMUM TRANSITION LENGTH
#define max_nt 10 // MAXIMUM ALLOWED NON TERMINAL
#define max_te 10 // MAXIMUM ALLOWED TERMINAL

char trans[max_tc][max_tl];
int trcnt = -1;

char nonterm[max_nt], term[max_te];
int ntcnt = 0, tecnt;

int res[max_te];


int isNonTerminal(char ch) { return (ch >= 'A' && ch <='Z') ? 1 : 0; }

int mapSymbol(char ch) {
	if(isNonTerminal(ch)) {
		for(int i = 0; i < ntcnt; i++) 
			if(nonterm[i] == ch)
				return i;
		nonterm[ntcnt++] = ch;
		return ntcnt - 1;
	}
	for(int i = 0; i < tecnt; i++) 
		if(term[i] == ch)
			return i;
	term[tecnt++] = ch;
	return tecnt - 1;
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

	fclose(fp);	printf("\n\n");
}

int first(char T) {
	int i, j, flag = 0;
	for(i = 0; i < trcnt; i++) {
		if(trans[i][0] == T) {
			for(j = 2; j < max_tl && trans[i][j] != T && trans[i][j] != '\0'; j++) {
				if(isNonTerminal(trans[i][j])) {
					if(!first(trans[i][j])) {
						flag = 0;
						break;
					}
					flag = 1;
				}  
				else {
					res[mapSymbol(trans[i][j])] = 1;
					if(trans[i][j] == '#') flag = 1;
					break;
				}
			}			
		}
	}
	return flag;
}
		
void main() {
	FILE *fp = fopen("gram.txt", "r");
	analyze(fp);
	
	int i, j;
	for(i = 0; i < ntcnt; i++) {
		for(j = 0; j < tecnt; j++) res[j] = 0;
		first(nonterm[i]);
		printf("First(%c)  = { ", nonterm[i]);
		for(j = 0; j < tecnt; j++) if(res[j]) printf("%c, ", term[j]);
		printf("}\n");
	}
}
