#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int openBrackets = 0, closedBrackets = 0;
    int maxPrefixRBS = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else {
                if (openBrackets > 0) {
                    openBrackets--;
                    maxPrefixRBS++;
                } else {
                    closedBrackets++;
                }
            }
        }
    }

    maxPrefixRBS += min(openBrackets, closedBrackets);

    cout << maxPrefixRBS << endl;

    return 0;
}