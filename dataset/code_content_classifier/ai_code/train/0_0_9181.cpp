#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    if (exp % 2 == 0) {
        long long half = power(base, exp / 2);
        return (half * half) % MOD;
    } else {
        return (base * power(base, exp - 1)) % MOD;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> startups(n);
    unordered_map<int, int> acquires;
    int active = 0;

    for (int i = 0; i < n; i++) {
        cin >> startups[i];
        if (startups[i] == -1) {
            active++;
        } else {
            acquires[startups[i]]++;
        }
    }

    int result = 0;
    for (auto& kvp : acquires) {
        result = (result + power(2, kvp.second) - 1) % MOD;
    }

    result = ((power(2, active) - 1 - result) + MOD) % MOD;

    cout << result << endl;

    return 0;
}