#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int power(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (1LL * result * a) % m;
        }
        a = (1LL * a * a) % m;
        b /= 2;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % m;
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int coefficient = 1;
        for (int j = 1; j <= n - i; j++) {
            coefficient = (1LL * coefficient * j) % m;
        }
        coefficient = (1LL * coefficient * power(fact[n - i], m - 2, m)) % m;
        if (i % 2 == 1) {
            answer = (answer + (1LL * coefficient * fact[i] * power(i, n, m)) % m) % m;
        } else {
            answer = (answer - (1LL * coefficient * fact[i] * power(i, n, m)) % m + m) % m;
        }
    }

    cout << answer << "\n";

    return 0;
}