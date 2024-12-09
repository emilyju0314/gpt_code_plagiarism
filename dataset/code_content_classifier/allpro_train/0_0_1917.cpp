#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<string> winner(n);

    char minChar = s[0];
    winner[0] = "Mike";

    for (int i = 1; i < n; i++) {
        if (s[i] > minChar) {
            winner[i] = "Mike";
            minChar = s[i];
        } else {
            winner[i] = "Ann";
        }
    }

    for (int i = 0; i < n; i++) {
        cout << winner[i] << endl;
    }

    return 0;
}