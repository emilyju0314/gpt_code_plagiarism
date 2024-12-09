#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n/k);
    vector<int> b(n/k);

    for(int i = 0; i < n/k; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n/k; i++) {
        cin >> b[i];
    }

    long long ans = 1;
    for(int i = 0; i < n; i += k) {
        long long possible_options = 0;
        for(int j = 0; j < 10; j++) {
            if(i == 0 && j == 0) continue;

            int block_num = 0;
            for(int l = 0; l < k; l++) {
                block_num = block_num * 10 + (l < k - 1 ? j : b[i/k]);
            }

            if(block_num % a[i/k] != 0) {
                possible_options++;
            }
        }

        ans = (ans * possible_options) % MOD;
    }

    cout << ans << endl;

    return 0;
}