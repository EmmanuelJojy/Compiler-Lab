#include <stdio.h>
#include <stdlib.h>
#define st 10 // Maximum allowable state
#define ch 10 // Maximum 10 unique charcters

struct state {
	int arr[st][ch];
	int inv[ch][st];
	int ecl[st];
	int nfa[ch][st];
};

struct state states[st];

int visited[st], seen[st];

char chMap[ch]; int chcnt = 0;

void eps(int org, int node) {
	if(visited[node]) return;
	visited[node] = 1; states[org].ecl[node] = 1;
	for(int i = 0; i < st; i++) if(states[org].arr[i][0] == 1)  eps(org, i);
}

int mapChar(char input)
{
	for(int i = 0; i < chcnt; i++)
		if(chMap[i] == input) 
			return i;
	chMap[chcnt++] = input;
	return chcnt - 1;
}

void main() {	
	chMap[chcnt++] = 'e';
	
	FILE *fp;
	fp = fopen("td.txt", "r");
	int start, final, index; char input;
	while(fscanf(fp, "%d %c %d", &start, &input, &final) != EOF) {
		seen[start] = 1; seen[final] = 1;
		index = mapChar(input);
		states[start].arr[final][index] = 1;
		states[start].inv[index][final] = 1;
	}
	fclose(fp);
	
	int i, j, k, l, m, n;
	for(i = 0; i < st; i++) {
		for(j = 0; j < st; j++) visited[j] = 0;
		eps(i, i);
	}
	
	// E NFA to NFA
	for(i = 0; i < st; i++) {
		for(j = 1; j < chcnt; j++) {
			for(k = 0; k < st; k++) {
				if(states[i].ecl[k] && seen[i] && seen[k]) {
					// i e k - Confirmed
					printf(">Confirming %d e %d\n", i, k);
					for(l = 0; l < st; l++) {
						if(states[k].inv[j][l]) {
							// k 'j' l - confirmed
							printf("\t>Confirming %d %c %d\n", i, chMap[j], k);
							for(m = 0; m < st; m++) {
								// my result is eclose(l)
								if(states[l].ecl[m]) {
									// l e m - confirmed
									printf("\t\t>Confirming %d e %d\n", l, m);
									states[i].nfa[j][m] = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	
	// printing results
	for(i = 0; i < st; i++) {
		for(j = 1; j < chcnt; j++) {
			for(k = 0; k < st; k++) {
				if(states[i].nfa[j][k]) {
					printf("%d %c %d\n", i, chMap[j], k);
				}
			}
		}
	}
}
