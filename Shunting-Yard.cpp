#include <bits/stdc++.h>
using namespace std;

// so co 1 chu so
// 1+2*3 -> 123*+

int calc(int a, int b, char o) {
    switch (o) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

main() {
    string s; cin>>s;
    int n = s.size();
    stack<char> op;
    stack<int> num;
    for (char c:s) {
        if ('0' <= c && c <= '9') {
            num.push(c - '0');
        } else {
            if (c == '*' || c == '/') op.push(c);
            else {
                if (op.empty()) {
                    op.push(c);
                } else {
                    while (op.top() == '*' || op.top() == '/') {
                        int a = num.top(); num.pop();
                        int b = num.top(); num.pop();
                        char o = op.top(); op.pop();
                        int res = calc(a, b, o);
                        num.push(res);
                    }
                    op.push(c);
                }
            }
        }
    }
    while (!op.empty()) {
        int a = num.top(); num.pop();
        int b = num.top(); num.pop();
        char o = op.top(); op.pop();
        int res = calc(a, b, o);
        num.push(res);
    }
    cout << num.top();
}
