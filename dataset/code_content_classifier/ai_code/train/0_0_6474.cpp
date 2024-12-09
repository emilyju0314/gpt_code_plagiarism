#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    string X;
    cin >> N >> X;
    
    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<string> dp(1<<N);
    dp[0] = "1";

    for(int i = 0; i < (1<<N); i++) {
        for(int j = 0; j < N; j++) {
            if(!(i & (1 << j))) {
                string new_str = A[j];
                int bit_count = 1;
                for(int k = 0; k < N; k++) {
                    if(i & (1 << k)) {
                        new_str = to_string(stoll(new_str) ^ stoll(A[k]));
                        bit_count++;
                    }
                }
                if(new_str <= X && (1 << bit_count) < dp[i].size()) {
                    dp[i | (1 << j)] = dp[i];
                } else {
                    dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % to_string(MOD);
                }
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}