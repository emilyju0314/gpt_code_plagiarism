#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minErasedSymbols(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int odd_count = 0;
    for (int f : freq) {
        if (f % 2 == 1) {
            odd_count++;
        }
    }

    if (odd_count > 1) {
        return -1;
    }

    int n = s.length();
    int min_erased = 0;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            min_erased++;
        }
    }

    return min_erased;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << minErasedSymbols(s) << endl;
    }

    return 0;
}