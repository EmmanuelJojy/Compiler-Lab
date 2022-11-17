#include <stdio.h>
#include <stdlib.h>
#define st 10 // Maximum allowable state

int arr[st][st];
int visited[st];
int seen[st];

void eps(int init) {
	if(visited[init]) return;
	visited[init] = 1; 
	printf("%d ", init);
	for(int i = 0; i < st; i++) if(arr[init][i] == 1)  eps(i);
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
		if(seen[i] != 1) continue;
		for(j = 0; j < st; j++) visited[j] = 0;
		printf("E-CLOSE(%d) = ", i);
		eps(i);
		printf("\n");
	}
}
