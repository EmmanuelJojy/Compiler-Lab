// TODO: Requires verification
// Certain inputs throw error

#include <stdio.h>
#include <string.h>
char op[2], arg1[5], arg2[5], result[5];
int main()
{
  FILE *fp;
  fp = fopen("in.txt", "r");
  while (fscanf(fp, "%s%s%s%s", op, arg1, arg2, result) != EOF)
  {
    if (strcmp(op, "+") == 0)
    {
      printf("MOV R0,%s\n", arg1);
      printf("ADD R0,%s\n", arg2);
      printf("MOV %s,R0\n", result);
    }
    if (strcmp(op, "*") == 0)
    {
      printf("MOV R0,%s\n", arg1);
      printf("MUL R0,%s\n", arg2);
      printf("MOV %s,R0\n", result);
    }
    if (strcmp(op, "-") == 0)
    {
      printf("MOV R0,%s\n", arg1);
      printf("SUB R0,%s\n", arg2);
      printf("MOV %s,R0\n", result);
    }
    if (strcmp(op, "/") == 0)
    {
      printf("MOV R0,%s\n", arg1);
      printf("DIV R0,%s\n", arg2);
      printf("MOV %s,R0\n", result);
    }
    if (strcmp(op, "=") == 0)
    {
      printf("MOV R0,%s\n", arg1);
      printf("MOV %s,R0\n", result);
    }
  }
  fclose(fp);
  return 0;
}
