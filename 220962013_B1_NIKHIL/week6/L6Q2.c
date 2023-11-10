#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    char stk[10];
    int tos;
} stack;
void push(stack *s, char c) {
    s->stk[++s->tos] = c;
}
char pop(stack *s) {
    return s->stk[s->tos--];
}
int isEmpty(stack *s) {
    return (s->tos == -1);
}
int getprec(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}
void revString(char st[]) {
    int len = strlen(st);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = st[i];
        st[i] = st[j];
        st[j] = temp;
    }
}
void inftopref(char inf[], char pref[]) {
    stack s;
    s.tos = -1; 
    int i, j = 0;
    revString(inf); 
    for (i = 0; inf[i] != '\0'; i++) {
        char ch = inf[i];
        if (isalnum(ch)) {
            pref[j++] = ch; 
        } else if (ch == ')') {
            push(&s, ch);
        } else if (ch == '(') {
            while (!isEmpty(&s) && s.stk[s.tos] != ')') {
                pref[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.stk[s.tos] == ')') {
                pop(&s);
            }
        } else {
            while (!isEmpty(&s) && getprec(ch) < getprec(s.stk[s.tos])) {
                pref[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) {
        pref[j++] = pop(&s);
    }
    pref[j] = '\0'; 
    revString(pref); 
}
int main() {
    char inf[50];
    char pref[50];
    printf("Enter infix:");
    scanf("%s", inf);
    inftopref(inf, pref);
    printf("Prefix: %s\n", pref);
    return 0;
}
