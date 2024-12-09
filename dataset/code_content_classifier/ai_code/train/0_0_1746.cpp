#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<int> open_brackets;
    stack<int> colors;
    int color = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (!open_brackets.empty()) {
                open_brackets.pop();
                colors.pop();
            }
        } else if (s[i] == 'R') {
            open_brackets.push(i);
            colors.push(color);
            color++;
        } else {
            int num_colors = 0;
            if (s[i] == '(') {
                if (!open_brackets.empty() && s[open_brackets.top()] == '(') {
                    num_colors = colors.top();
                }
                open_brackets.push(i);
                colors.push(num_colors);
            } else if (s[i] == ')') {
                if (!open_brackets.empty() && s[open_brackets.top()] == '(') {
                    num_colors = colors.top();
                    colors.pop();
                    open_brackets.pop();
                } else {
                    num_colors = -1;
                }
            }
            cout << num_colors << " ";
        }
    }

    return 0;
}