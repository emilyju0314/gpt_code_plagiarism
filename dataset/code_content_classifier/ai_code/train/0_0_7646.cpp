#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        long long ans = 1;
        for (int i = 0; i < s.length(); i++) {
            ans *= 26; // there are 26 possibilities for each character
            ans %= MOD;
        }

        // subtract 1 to exclude the original word
        ans = (ans - 1 + MOD) % MOD;

        cout << ans << endl;
    }

    return 0;
}