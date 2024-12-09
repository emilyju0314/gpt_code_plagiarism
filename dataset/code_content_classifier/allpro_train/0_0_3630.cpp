#include <iostream>
#include <string>

using namespace std;

bool isStringLiteral(char c) {
    return c == '"';
}

bool areCloseSubmissions(string s1, string s2) {
    if (s1 == s2) {
        cout << "IDENTICAL" << endl;
        return false;
    }

    int diffCount = 0;
    bool inStringLiteral = false;

    for (int i = 0; i < s1.length(); i++) {
        if (isStringLiteral(s1[i])) {
            inStringLiteral = !inStringLiteral;
        }
        if (inStringLiteral && s1[i] != s2[i]) {
            diffCount++;
        }
    }

    if (diffCount == 2) {
        cout << "CLOSE" << endl;
    } else {
        cout << "DIFFERENT" << endl;
    }

    return true;
}

int main() {
    string s1, s2;

    while (true) {
        cin >> s1;
        if (s1 == ".") {
            break;
        }

        cin >> s2;

        areCloseSubmissions(s1, s2);
    }

    return 0;
}