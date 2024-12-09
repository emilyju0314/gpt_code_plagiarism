#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    long long ways = 1;
    for (int i = 1; i < n; i++) {
        ways = (ways * m) % MOD;
    }

    cout << ways << endl;

    return 0;
}