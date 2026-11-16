#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string postfix(string exp) {
    stack<char> s;
    string out;

    for (char c : exp) {
        if (isalnum(c)) out += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (s.top() != '(') { out += s.top(); s.pop(); }
            s.pop();
        } else {
            while (!s.empty() && prec(s.top()) >= prec(c)) {
                out += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) { out += s.top(); s.pop(); }
    return out;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix: " << postfix(exp) << '\n';

    reverse(exp.begin(), exp.end());
    for (char& c : exp) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string pre = postfix(exp);
    reverse(pre.begin(), pre.end());
    cout << "Prefix: " << pre << '\n';
}