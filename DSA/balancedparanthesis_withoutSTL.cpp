#include <iostream>
using namespace std;

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkBalancedParanthesis(const char* s) {
    int n = 0;
    while (s[n] != '\0') n++;   // manual strlen

    char* stack = new char[n];  // stack array
    int top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // Opening brackets → push
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // Closing brackets → pop & match
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                delete[] stack;
                return false;
            }

            char open = stack[top--];
            if (!isMatching(open, ch)) {
                delete[] stack;
                return false;
            }
        }
    }

    bool balanced = (top == -1);
    delete[] stack;
    return balanced;
}
