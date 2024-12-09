#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int diversity = 0;
    vector<int> diversityCount(n, 0); // To store the count of substrings with diversity i

    for (int i = 0; i < n; i++) {
        vector<int> cnt(26, 0); // To store the count of each character in the current substring
        int distinctCount = 0;
        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            if (cnt[idx] == 0) {
                distinctCount++;
            }
            cnt[idx]++;
            diversityCount[distinctCount - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (diversityCount[i] != 0) {
            diversity++;
        } else {
            break;
        }
    }

    cout << diversity << endl;
    for (int i = 0; i < diversity; i++) {
        cout << diversityCount[i] << endl;
    }

    return 0;
}