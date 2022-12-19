// Target Grammer
// E -> E+T|T
// T -> T*F|F
// F -> (E)|id
//
// Without left recursion and after left factoring
// E  -> TE'
// E' -> +TE'|∈
// T  -> FT'
// T' -> *FT'|∈
// F  -> (E)|id

#include <stdio.h>
#include <ctype.h>

char s[64];
int cnt = 0;

int E(), E_(), T(), T_(), F();

int main() {
    printf("Enter Expression to Validate: ");
    scanf("%s", s);

    if(E()) 
        printf("Expression is Valid.\n");
    else
        printf("Expression is Invalid.\n");
    return 0;
}

int E() {
    if(T()) 
        if(E_())
            return 1;
    return 0;
}

int E_() {
    if(s[cnt] == '+') {
        cnt++;
        if(T()) 
            if(E_())               
                return 1;
        return 0;
    }
    return 1;
}

int T() {
    if(F()) 
        if(T_()) 
            return 1;
    return 0;
}

int T_() {
    if(s[cnt] == '*') {
        cnt++;
        if(F())
            if(T_())
                return 1;
        return 0;
    }
    return 1;
}

int F() {
    if(s[cnt] == '(') {
        cnt++;
        if(E()) {
            if(s[cnt] == ')') {
                cnt++;
                return 1;
            }
        }
    }
    else if(isalnum(s[cnt])) {
        cnt++;
        return 1;
    }
    return 0;
}