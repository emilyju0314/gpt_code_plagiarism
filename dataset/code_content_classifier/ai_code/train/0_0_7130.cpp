#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> left, right;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == 'l') {
            right.push(i + 1);
        } else {
            left.push(i + 1);
        }
    }

    while (!left.empty()) {
        cout << left.top() << endl;
        left.pop();
    }

    while (!right.empty()) {
        cout << right.top() << endl;
        right.pop();
    }

    return 0;
}