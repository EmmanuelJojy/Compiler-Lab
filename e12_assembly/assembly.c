#include <stdio.h>
int main() {
  FILE *fp;
  char op[2], arg1[5], arg2[5], result[5];
  fp = fopen("in.txt", "r");
  while (fscanf(fp, "%s%s%s%s", op, arg1, arg2, result) != EOF)  {
    printf("MOV R0,%s\n", arg1);
    switch (op[0]) {
      case '+': printf("ADD R0,%s\n", arg2); break;
      case '-': printf("SUB R0,%s\n", arg2); break;
      case '*': printf("MUL R0,%s\n", arg2); break;
      case '/': printf("DIV R0,%s\n", arg2); break;
    }
    printf("MOV %s,R0\n", result);
  }
  fclose(fp);
  return 0;
}