#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubsequence(const string& a, const string& b) {
    int i = 0, j = 0;
    while (i < a.length() && j < b.length()) {
        if (a[i] == b[j]) {
            j++;
        }
        i++;
    }
    return j == b.length();
}

int main() {
    string A;
    cin >> A;

    vector<bool> used(26, false);

    for (char c : A) {
        used[c - 'a'] = true;
    }

    string answer = "";
    for (char c = 'a'; c <= 'z'; c++) {
        if (!used[c - 'a']) {
            answer = c;
            break;
        }
    }

    if (answer.empty()) {
        for (char c = 'a'; c <= 'z'; c++) {
            for (char d = 'a'; d <= 'z'; d++) {
                string check = "";
                check += c;
                check += d;
                if (!isSubsequence(A, check)) {
                    answer = check;
                    break;
                }
            }
            if (!answer.empty()) break;
        }
    }

    cout << answer << endl;

    return 0;
}