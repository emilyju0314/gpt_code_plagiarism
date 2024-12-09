#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size();
    long long ans = 1;

    for(int i = 0; i < n; i++) {
        int diff = b[i] - a[i];
        ans = (ans * diff) % MOD;
    }

    cout << (ans - 1 + MOD) % MOD << endl;

    return 0;
}