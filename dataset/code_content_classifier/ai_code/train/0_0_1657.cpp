#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n;
    long long T;
    cin >> n >> T;

    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    long long num_solved = 0;
    long long total_time = 0;
    long long ans = 0;

    for(int i = 0; i < n; i++) {
        if(total_time + t[i] <= T) {
            num_solved++;
            total_time += t[i];
        } else {
            break;
        }
    }

    ans = num_solved;

    long long p = 1;
    for(int i = 0; i < n; i++) {
        long long p_odd = (p + 1) % MOD;
        long long p_even = p % MOD;
        ans = (ans + (num_solved * p_even) % MOD) % MOD;
        p = (p * 2) % MOD;
    }

    cout << ans << endl;

    return 0;
}