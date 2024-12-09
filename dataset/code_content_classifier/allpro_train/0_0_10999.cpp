#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;

    map<int, vector<char>> allowedLetters;
    for(int i = 0; i < m; i++) {
        int pos;
        string letters;
        cin >> pos >> letters;
        allowedLetters[pos - 1] = vector<char>(letters.begin(), letters.end()); // index pos is 1-based
    }

    for(int i = 0; i < s.length(); i++) {
        if(allowedLetters.find(i) != allowedLetters.end()) {
            sort(allowedLetters[i].begin(), allowedLetters[i].end());
            if(find(allowedLetters[i].begin(), allowedLetters[i].end(), s[i]) == allowedLetters[i].end()) {
                s[i] = allowedLetters[i][0];
            }
        }
    }

    cout << s << endl;

    return 0;
}