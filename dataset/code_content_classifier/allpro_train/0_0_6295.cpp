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

    sort(A.begin(), A.end());

    long long ans = 1;
    for (int i = 0; i < N; i++) {
        ans = (ans * A[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}