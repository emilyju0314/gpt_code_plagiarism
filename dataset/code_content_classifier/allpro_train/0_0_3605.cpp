#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int tFreq[26] = {0};
    for(char c : t) {
        tFreq[c - 'a']++;
    }

    int questionMarks = 0;
    int tLength = t.length();
    for(char c : s) {
        if (c == '?') {
            questionMarks++;
        }
    }

    int maxSuitability = 0;
    string result = s;

    for (char c = 'a'; c <= 'z'; c++) {
        string temp = s;
        int currentSuitability = 0;

        for (int i = 0; i < s.length(); i++) {
            if (temp[i] == '?' || temp[i] == c) {
                temp[i] = c;
                currentSuitability += (i >= tLength && temp.substr(i - tLength, tLength) == t);
            }
        }

        for (int i = tLength; i < s.length(); i++) {
            int removeCharIndex = i - tLength;
            if (temp[removeCharIndex] == '?') {
                questionMarks--;
            } else {
                temp[removeCharIndex] = s[removeCharIndex];
            }
            if (temp[i] == '?') {
                questionMarks++;
            } else if (temp[i] == c) {
                currentSuitability += (temp.substr(i - tLength + 1, tLength) == t);
            }
            if (questionMarks < 0) {
                currentSuitability -= (temp[removeCharIndex] == c && tFreq[c - 'a'] > 0 && temp.substr(i - tLength + 1, tLength) == t);
                questionMarks++;
                temp[removeCharIndex] = '?';
            }
        }

        if (currentSuitability > maxSuitability) {
            maxSuitability = currentSuitability;
            result = temp;
        }
    }

    cout << result << endl;

    return 0;
}