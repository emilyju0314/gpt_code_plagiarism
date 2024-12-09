#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        char type;
        int l, r, x, k;
        cin >> type >> l >> r >> x;

        if (type == '=') {
            for (int j = l - 1; j <= r - 1; j++) {
                arr[j] = x;
            }
        } else {
            long long sum = 0;
            for (int j = l - 1; j <= r - 1; j++) {
                sum += arr[j] % MOD;
            }

            if (x == 0) {
                cout << sum % MOD << endl;
            } else {
                long long result = 1;
                for (int j = 0; j < x; j++) {
                    result *= sum;
                    result %= MOD;
                }

                cout << result << endl;
            }
        }
    }

    return 0;
}