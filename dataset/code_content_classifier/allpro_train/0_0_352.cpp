#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> factors(n);
    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        cin >> factors[i];
        freq[factors[i]]++;
    }

    long long ans = 1;
    for(auto it : freq) {
        int count = it.second;
        long long sum = 0;
        long long prod = 1;

        for(int i = 0; i <= count; i++) {
            sum = (sum + prod) % MOD;
            prod = (prod * 2) % MOD;
        }

        ans = (ans * sum) % MOD;
    }

    cout << ans << endl;

    return 0;
}