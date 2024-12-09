#include <iostream>
#include <string>
#define MOD 998244353

using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    int left_count = 1, right_count = 0;

    char left = s[0], right = s[n-1];

    for(int i = 1; i < n; i++) {
        if(s[i] == left) {
            left_count++;
        } else {
            break;
        }
    }

    for(int i = n-2; i >= 0; i--) {
        if(s[i] == right) {
            right_count++;
        } else {
            break;
        }
    }

    if(left == right) {
        long long ans = (left_count + 1) * (right_count + 1);
        ans %= MOD;
        cout << ans << endl;
    } else {
        long long ans = (left_count + right_count + 1) % MOD;
        cout << ans << endl;
    }

    return 0;
}