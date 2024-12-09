#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;

        int changes = 0;
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < k / 2; i++) {
            int maxFreq = 0;
            for (int j = 0; j < 26; j++) {
                maxFreq = max(maxFreq, min(freq[j] - (i == 0 || i == k / 2 - 1), freq[j] - (i == 0 && k % 2 == 1)));
            }
            changes += n / k - maxFreq;
        }

        cout << changes << endl;
    }

    return 0;
}