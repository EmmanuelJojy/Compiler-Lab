#include <stdio.h>
#include <stdlib.h>
#define st 10 // Maximum allowable state

int arr[st][st];
int ecl[st][st];
int visited[st];
int seen[st];

void eps(int org, int node) {
	// org refers to starter of eps call
	// node is epsilon transition targets
	if(visited[node]) return;
	visited[node] = 1; 
	ecl[org][node] = 1;
	for(int i = 0; i < st; i++) if(arr[node][i] == 1)  eps(org, i);
}

void main() {
	FILE *fp;
	fp = fopen("td.txt", "r");
	int start, final; char input;
	while(fscanf(fp, "%d %c %d", &start, &input, &final) != EOF) {
		seen[start] = 1; seen[final] = 1;
		if(input == 'e') arr[start][final] = 1;
	}
	fclose(fp);
	
	// Invoke recursive eps()
	int i, j;
	for(i = 0; i < st; i++) {
		for(j = 0; j < st; j++) visited[j] = 0;
		eps(i, i);
	}
	
	
}
