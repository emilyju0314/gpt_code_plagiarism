#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int F, B;
    long long N;
    cin >> F >> B >> N;

    vector<int> petals(F);
    vector<int> chocolates(B);

    for(int i = 0; i < F; i++) {
        cin >> petals[i];
    }

    for(int i = 0; i < B; i++) {
        cin >> chocolates[i];
    }

    vector<long long> dp1(N+1, 0);
    vector<long long> dp2(N+1, 0);

    dp1[0] = 1;
    dp2[0] = 1;

    for(int i = 0; i < F; i++) {
        for(int j = N; j >= petals[i]; j--) {
            dp1[j] += dp1[j - petals[i]];
            dp1[j] %= MOD;
        }
    }

    for(int i = 0; i < B; i++) {
        for(int j = N; j >= chocolates[i]; j--) {
            dp2[j] += dp2[j - chocolates[i]];
            dp2[j] %= MOD;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += (dp1[i] * dp2[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}