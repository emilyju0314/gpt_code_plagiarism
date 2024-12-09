#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long ways = 1;

    for(int i = 0; i < m; i++) {
        ways = (ways * 2) % MOD;
    }

    for(int i = 0; i < n; i++) {
        ways = (ways - 1 + MOD) % MOD;
    }

    cout << ways << endl;

    return 0;
}