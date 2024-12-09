#include <iostream>
#include <string>

using namespace std;

int countOccurrences(string s, string t) {
    int count = 0;
    for (int i = 0; i <= s.length() - t.length(); i++) {
        bool match = true;
        for (int j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    return count;
}

int main() {
    string s, t;
    cin >> s >> t;

    int maxOccurrences = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        string ss = s;
        for (int i = 0; i < ss.length(); i++) {
            if (ss[i] == '?') {
                ss[i] = c;
            }
        }
        int occurrences = countOccurrences(ss, t);
        if (occurrences > maxOccurrences) {
            maxOccurrences = occurrences;
        }
    }

    cout << maxOccurrences << endl;

    return 0;
}