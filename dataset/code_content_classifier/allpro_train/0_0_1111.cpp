#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long ans = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        ans = (ans + (A[i] - i - 1) * fact[N - i - 1]) % MOD;
    }

    cout << ans << endl;

    return 0;
}