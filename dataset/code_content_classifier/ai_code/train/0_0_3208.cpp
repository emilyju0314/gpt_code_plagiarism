#include <iostream>
#include <string>

using namespace std;

int countRegularBrackets(string s) {
    int n = s.length();
    int open = 0, close = 0, result = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            open++;
        } else {
            close++;
        }
    }

    if (open != close) {
        return 0;
    }

    int balance = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            balance++;
        } else {
            balance--;
            if (balance == 0) {
                result++;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int result = countRegularBrackets(s);
    cout << result << endl;

    return 0;
}