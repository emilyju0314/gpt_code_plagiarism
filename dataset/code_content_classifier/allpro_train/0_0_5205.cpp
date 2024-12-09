#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int cnt = 0;
    int open = 0;
    int close = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            open++;
        } else {
            close++;
        }

        if (close > open) {
            cnt++;
            close--;
        }
    }

    if (open == close && cnt <= 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}