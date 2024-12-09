#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        long long ans = 1;
        for (int i = 0; i < 26; i++) {
            ans = (ans * factorial(freq[i])) % MOD;
        }

        ans = (ans - 1 + MOD) % MOD;
        cout << ans << endl;
    }

    return 0;
}