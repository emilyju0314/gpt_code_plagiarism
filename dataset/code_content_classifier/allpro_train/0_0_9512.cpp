#include <iostream>
#include <string>
#include <stack>

using namespace std;

string shortestCorrectBracketSequence(int N, string S) {
    stack<char> st;
    int open = 0, close = 0;

    for (char& c : S) {
        if (c == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }

    string result = string(open, '(') + S + string(close, ')');
    return result;
}

int main() {
    int N;
    string S;

    cin >> N >> S;

    cout << shortestCorrectBracketSequence(N, S) << endl;

    return 0;
}