#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        unordered_map<char, int> count;
        int uniqueCount = 0;
        int i = 0, j = 0, minLen = INT_MAX;

        for (char c : s) {
            count[c]++;
            if (count[c] == 1) {
                uniqueCount++;
            }

            while (uniqueCount == 3) {
                minLen = min(minLen, j - i + 1);
                if (--count[s[i]] == 0) {
                    uniqueCount--;
                }
                i++;
            }
            j++;
        }

        if (minLen == INT_MAX) {
            cout << 0 << endl;
        } else {
            cout << minLen << endl;
        }
    }

    return 0;
}