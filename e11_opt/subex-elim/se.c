#include <stdio.h>
#include <string.h>

struct statement {
    char op[2], a1[4], a2[4], res[4];
    int ignore; 
};

struct statement st[32];
int cnt = 0;

void replace(char *targ, char *repl, int i) {
    // replace targ with repl
    st[i].ignore = 1;
    for(int j = i + 1; j < cnt; j++) {
        if(!strcmp(targ, st[j].a1)) sprintf(st[j].a1, "%s", repl);
        if(!strcmp(targ, st[j].a2)) sprintf(st[j].a2, "%s", repl);
    }
}

int main() {
    FILE *fp;
    fp = fopen("in.txt", "r");
    while(fscanf(fp, "%s %s %s %s", st[cnt].op, st[cnt].a1, st[cnt].a2, st[cnt].res) != EOF) cnt++;
    fclose(fp);

    for(int i = 0; i < cnt; i++)
        for(int j = i + 1; j < cnt; j++)
            if(st[i].op[0] == st[j].op[0] && !strcmp(st[i].a1, st[j].a1) && !strcmp(st[i].a2, st[j].a2))
                replace(st[j].res, st[i].res, j);

    printf("Common Sub-expression eliminated code: \n");
    printf("OPR\tA1\tA2\tRES\n");
    for(int i = 0; i < cnt; i++) {
        if(st[i].ignore == 1) continue;
        printf("%s\t%s\t%s\t%s\n", st[i].op, st[i].a1, st[i].a2, st[i].res);
    }
    return 0;
}