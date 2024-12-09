#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long ans = 0;
        for (int s1 = 0; s1 <= N; s1++) {
            for (int s2 = s1 + 1; s2 <= N - s1; s2++) {
                for (int n1 = 0; n1 <= N - s1 - s2; n1++) {
                    for (int n2 = n1 + 1; n2 <= N - s1 - s2 - n1; n2++) {
                        for (int u1 = 0; u1 <= N - s1 - s2 - n1 - n2; u1++) {
                            for (int u2 = u1 + 1; u2 <= N - s1 - s2 - n1 - n2 - u1; u2++) {
                                for (int k1 = 0; k1 <= N - s1 - s2 - n1 - n2 - u1 - u2; k1++) {
                                    for (int k2 = k1 + 1; k2 <= N - s1 - s2 - n1 - n2 - u1 - u2 - k1; k2++) {
                                        for (int e1 = 0; e1 <= N - s1 - s2 - n1 - n2 - u1 - u2 - k1 - k2; e1++) {
                                            int e2 = N - s1 - s2 - n1 - n2 - u1 - u2 - k1 - k2 - e1;
                                            ans = (ans + (long long)(s2 - s1) * (n2 - n1) * (u2 - u1) * (k2 - k1) * (e2 - e1)) % MOD;
                                        }
                                    }
                                }
                            }
                        }
                    }   
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}