#include <stdio.h>
#define tr 20 // MAX TRANSITIONS
#define tl 10 // MAX TRANS LENGTH
#define ch 10 // MAX TERMINAL
#define nt 10 // MAX NON-TERM

char trans[tr][tl];
int trcnt = -1;

void analyze_file(FILE *fp) 
{
    char s[32], left;
    while(fscanf(fp, "%s", s) != EOF) 
    {
        for(int i = 0, tlcnt = 0; i < 32 && s[i] != '\0'; i++) 
        {
            if(s[i] == '=') continue;
            if(s[i] == '|') 
            {
                trans[trcnt][tlcnt] = '\0'; 
                tlcnt = 0;
            }
            if(i == 0 || s[i] == '|') 
            {   
                trcnt += 1;
                trans[trcnt][tlcnt++] = s[0];
                trans[trcnt][tlcnt++] = '=';
                continue;
            }
            trans[trcnt][tlcnt++] = s[i];            
        }
    }

    for(int i = 0; i <= trcnt; i++) {
        printf("%s\n", trans[i]);
    }
}

void main() 
{
    FILE *fp = fopen("gram.txt", "r");
    analyze_file(fp);
    fclose(fp);
}