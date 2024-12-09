#include <iostream>
#include <string>

using namespace std;

string findParenthesisSequence(int n, string s) {
    int openCount = 0;
    int unknownCount = 0;
    for(char c : s) {
        if(c == '(') {
            openCount++;
        } else if(c == ')') {
            if(openCount > 0) {
                openCount--;
            } else if(unknownCount > 0) {
                unknownCount--;
            } else {
                return ":(";
            }
        } else {
            unknownCount++;
        }
    }

    int closeCount = openCount + unknownCount;
    if(closeCount % 2 != 0) {
        return ":(";
    }

    string result = "";
    openCount = closeCount / 2;
    for(char c : s) {
        if(c == '?') {
            if(openCount > 0) {
                result += '(';
                openCount--;
            } else {
                result += ')';
            }
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    string result = findParenthesisSequence(n, s);
    cout << result << endl;

    return 0;
}