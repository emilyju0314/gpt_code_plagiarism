#include <iostream>
using namespace std;

const int mod = 998244353;

int main() {
    int n;
    cin >> n;

    long long lucky_colorings = 1;
    for(int i = 0; i < n * n; i++) {
        lucky_colorings = (lucky_colorings * 3) % mod;
    }

    long long a = 3;
    for(int i = 1; i < n; i++) {
        a = (a * 3) % mod;
    }
    a = (a - 3 + mod) % mod;
    a = (a * n) % mod;

    lucky_colorings = (lucky_colorings - a + 3 + mod) % mod;

    cout << lucky_colorings << endl;
    
    return 0;
}