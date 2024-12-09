#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        string s;
        cin >> s;

        long long len = s.size();
        long long ans = s.size();

        int i = 1;
        while (i < x) {
            len = (len + (len - i) * (s[i - 1] - '1')) % MOD;
            ans = (ans + len * (s[i - 1] - '1')) % MOD;
            i++;
        }

        cout << ans << endl;
    }

    return 0;
}