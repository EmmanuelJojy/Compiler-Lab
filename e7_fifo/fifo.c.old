#include <stdio.h>
#define tr 20 // MAX TRANSITIONS
#define tl 10 // MAX TRANS LENGTH
#define ch 10 // MAX TERMINAL
#define nt 10 // MAX NON-TERM

char trans[tr][tl];
int trcnt = -1;

char T[ch], NT[nt];
int tcnt = 0, ntcnt = 0;

int isTerminal(char in)
{
    return (in >= 'A' && in <= 'Z') ? 1 : 0;
}

int mapTerminal(char in)
{
    for (int i = 0; i <= tcnt; i++)
        if (T[i] == in)
            return i;
    T[tcnt++] = in;
    return tcnt - 1;
}

int mapNonTerminal(char in)
{
    for (int i = 0; i <= ntcnt; i++)
        if (NT[i] == in)
            return i;
    NT[ntcnt++] = in;
    return ntcnt - 1;
}

void analyze_file(FILE *fp)
{
    char s[32], left;
    while (fscanf(fp, "%s", s) != EOF)
    {
        for (int i = 0, tlcnt = 0; i < 32 && s[i] != '\0'; i++)
        {
            if (s[i] == '=')
                continue;

            if (s[i] == '|')
            {
                trans[trcnt][tlcnt] = '\0';
                tlcnt = 0;
            }
            else
            {
                if (isTerminal(s[i]))
                    mapTerminal(s[i]);
                else
                    mapNonTerminal(s[i]);
            }
            if (i == 0 || s[i] == '|')
            {
                trcnt += 1;
                trans[trcnt][tlcnt++] = s[0];
                trans[trcnt][tlcnt++] = '=';
                continue;
            }
            trans[trcnt][tlcnt++] = s[i];
        }
    }
}

void first(char T)
{
    for (int i = 0; i <= trcnt; i++)
    {
        if (trans[i][0] == T)
        {
            if (!isTerminal(trans[i][2]))
                printf("%c, ", trans[i][2]);
            else
                first(trans[i][2]);
        }
    }
}

void follow(char T)
{
    for (int i = 0; i <= trcnt; i++)
    {
        for (int j = 2; trans[i][j] != '\0'; j++)
        {
            if (trans[i][j] == T)
            {
                if (trans[i][j + 1] == '\0')
                {
                    if (trans[i][0] != T)
                        follow(trans[i][0]);
                }
                else
                {
                    if (!isTerminal(trans[i][j + 1]))
                        printf("%c, ", trans[i][j + 1]);
                    else
                        first(trans[i][j + 1]);
                }
            }
        }
    }
}

void main()
{
    FILE *fp = fopen("gram.txt", "r");
    analyze_file(fp);
    fclose(fp);

    char prev = '!';
    for (int i = 0; i < tcnt; i++)
    {
        if (prev == T[i])
            continue;
        printf("FIRST(%c): { ", T[i]);
        first(T[i]);
        printf("}\n");
        prev = T[i];
    }

    for (int i = 0; i < tl; i++)
        if (trans[0][i] == '\0')
        {
            trans[0][i] = '$';
            trans[0][i + 1] = '\0';
        }

    printf("\n");
    prev = '!';
    for (int i = 0; i < tcnt; i++)
    {
        if (prev == T[i])
            continue;
        printf("FOLLOW(%c): { ", T[i]);
        follow(T[i]);
        printf("}\n");
        prev = T[i];
    }
}