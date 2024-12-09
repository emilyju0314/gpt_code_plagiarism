#include <iostream>
#include <stack>

using namespace std;

int main() {
    string formula;
    getline(cin, formula);

    stack<char> stack;
    int zero_count = 0;
    int one_count = 0;

    for (char c : formula) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            stack.pop();
        } else if (c == '&') {
            if (!stack.empty() && stack.top() == '?') {
                zero_count++;
                stack.pop();
            }
        } else if (c == '|') {
            if (!stack.empty() && stack.top() == '?') {
                one_count++;
                stack.pop();
            }
        } else if (c == '?') {
            stack.push(c);
        }
    }

    cout << zero_count << " " << one_count << endl;

    return 0;
}