#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define MOD 1000000007

using namespace std;

long long countBinaryNumbers(string A, string B, int c00, int c01, int c10, int c11) {
    int n = B.length();
    vector<long long> dp0(n + 1), dp1(n + 1), dp2(n + 1), dp3(n + 1);
    dp0[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp0[i] = dp0[i - 1];
        dp1[i] = dp1[i - 1];
        dp2[i] = dp2[i - 1];
        dp3[i] = dp3[i - 1];

        if (B[i - 1] == '0') {
            dp0[i] = (dp0[i] * 2) % MOD;
        } else {
            dp1[i] = (dp1[i] * 2) % MOD;
        }
        if (B[i - 1] == '0' && B[i - 2] == '0') {
            dp0[i] = (dp0[i] + dp1[i - 2]) % MOD;
        }
        if (B[i - 1] == '1' && B[i - 2] == '0') {
            dp1[i] = (dp1[i] + dp0[i - 2]) % MOD;
        }
        if (B[i - 1] == '0' && B[i - 2] == '1') {
            dp2[i] = (dp2[i] + dp3[i - 2]) % MOD;
        }
        if (B[i - 1] == '1' && B[i - 2] == '1') {
            dp3[i] = (dp3[i] + dp2[i - 2]) % MOD;
        }
    }

    long long result = (dp0[n] + dp1[n] + dp2[n] + dp3[n]) % MOD;

    // Subtract the count for numbers less than A from the count for numbers less than or equal to B
    if (A != "1") {
        n = A.length();
        dp0.assign(n + 1, 0);
        dp1.assign(n + 1, 0);
        dp2.assign(n + 1, 0);
        dp3.assign(n + 1, 0);
        dp0[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp0[i] = dp0[i - 1];
            dp1[i] = dp1[i - 1];
            dp2[i] = dp2[i - 1];
            dp3[i] = dp3[i - 1];

            if (A[i - 1] == '0') {
                dp0[i] = (dp0[i] * 2) % MOD;
            } else {
                dp1[i] = (dp1[i] * 2) % MOD;
            }
            if (A[i - 1] == '0' && A[i - 2] == '0') {
                dp0[i] = (dp0[i] + dp1[i - 2]) % MOD;
            }
            if (A[i - 1] == '1' && A[i - 2] == '0') {
                dp1[i] = (dp1[i] + dp0[i - 2]) % MOD;
            }
            if (A[i - 1] == '0' && A[i - 2] == '1') {
                dp2[i] = (dp2[i] + dp3[i - 2]) % MOD;
            }
            if (A[i - 1] == '1' && A[i - 2] == '1') {
                dp3[i] = (dp3[i] + dp2[i - 2]) % MOD;
            }
        }

        result = (result - (dp0[n] + dp1[n] + dp2[n] + dp3[n]) % MOD + MOD) % MOD;
    }

    return result;
}

int main() {
    string A, B;
    cin >> A >> B;
    
    int c00, c01, c10, c11;
    cin >> c00 >> c01 >> c10 >> c11;

    long long result = countBinaryNumbers(A, B, c00, c01, c10, c11);
    cout << result << endl;

    return 0;
}