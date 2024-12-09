#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        vector<int> perm = S;
        swap(perm[i], perm[0]); // Try every possible permutation by swapping elements

        int curr = X;
        for (int j = 1; j < N; j++) {
            curr = curr % perm[j]; // Perform the operation described
        }

        ans = (ans + curr) % MOD; // Add the final number to the answer modulo MOD
    }

    cout << ans << endl;

    return 0;
}