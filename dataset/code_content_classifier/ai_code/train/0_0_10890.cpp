#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;
    
    int s = 0;
    vector<int> A(1 << N);
    for (int i = 0; i < (1 << N); i++) {
        cin >> A[i];
        s += A[i];
    }
    
    vector<int> ans(1 << N, 0);
    ans[0] = 0;
    for (int i = 1; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) != 0) {
                ans[i] = (ans[i] + 1LL * ans[i ^ (1 << j)] * A[i] % MOD * 499122177 % MOD) % MOD;
            }
        }
    }
    
    for (int i = 0; i < (1 << N); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}