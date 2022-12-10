// Target Grammer
// E -> E+E|E*E|(E)|id

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stk[64], inp[64];
int scnt = 0, icnt = 0;

int reduce(char ch, int index, char *trans) {
    scnt = index;
    stk[scnt] = ch;
    stk[scnt + 1] = '\0'; 
    printf("%s\t|\t%s\n", stk, trans);
    return 1;
}

int check() {
    //if(scnt - 2 > 0) {
        if(stk[scnt] == 'E' && stk[scnt - 1] == '+' && stk[scnt - 2] == 'E') return reduce('E', scnt - 2, "E -> E + E");
        if(stk[scnt] == 'E' && stk[scnt - 1] == '*' && stk[scnt - 2] == 'E') return reduce('E', scnt - 2, "E -> E * E");
        if(stk[scnt] == ')' && stk[scnt - 1] == 'E' && stk[scnt - 2] == '(') return reduce('E', scnt - 2, "E -> ( E )");
    //}
    if(isalnum(stk[scnt]) && stk[scnt] != 'E') return reduce('E', scnt, "E -> id");
    return 0;
}

int main() {
    printf("Enter Expression to Validate: ");
    scanf("%s", inp);

    stk[scnt] = '$';
    stk[scnt + 1] = '\0';

    printf("STACK\t|\tREDUCTION\n");
    printf("-------------------------\n");
    for(int i = 0; i < 64 && inp[i] != '\0'; i++) {
        stk[++scnt] = inp[icnt++];
        printf("%s\t|\n", stk);
        while(check());
    }

    if(!strcmp(stk, "$E"))
        printf("\nValid Expression.\n");
    else
        printf("\nInvalid Expression.\n");
    
    return 0;
}