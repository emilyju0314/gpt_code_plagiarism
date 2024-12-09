#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> factors(n);
    map<int, int> primeFactors;

    for (int i = 0; i < n; i++) {
        cin >> factors[i];

        int num = factors[i];
        for (int j = 2; j * j <= num; j++) {
            while (num % j == 0) {
                primeFactors[j]++;
                num /= j;
            }
        }
        if (num > 1) {
            primeFactors[num]++;
        }
    }

    long long result = 1;
    for (auto factor : primeFactors) {
        result = (result * (factor.second + n - 1)) % MOD;
    }

    cout << result << endl;

    return 0;
}