#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countHappyCuts(string s, string t) {
    int count = 0;
    int sLength = s.length();
    int tLength = t.length();

    vector<int> prefix(sLength, 0);
    int j = 0;
    for (int i = 0; i < tLength; i++) {
        if (t[i] == s[j]) {
            prefix[j++] = i;
            if (j == sLength) {
                break;
            }
        }
    }

    if (j < sLength - 1) {
        return 0;
    }

    j = 0;
    for (int i = tLength - 1; i >= 0; i--) {
        if (t[i] == s[sLength - 1 - j]) {
            int prev = prefix[sLength - 1 - j];
            if (prev < i) {
                count++;
            }
            j++;
            if (j == sLength) {
                break;
            }
        }
    }

    return count;
}

int main() {
    string s, t;
    cin >> s >> t;

    int result = countHappyCuts(s, t);
    cout << result << endl;

    return 0;
}