#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<long long> prime_factors(long long n) {
    set<long long> factors;

    while (n % 2 == 0) {
        factors.insert(2);
        n = n / 2;
    }

    for (long long i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            factors.insert(i);
            n = n / i;
        }
    }

    if (n > 2) {
        factors.insert(n);
    }

    return factors;
}

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int vertices = 0;
    set<long long> factors_set;

    for (int i = 0; i < n; i++) {
        set<long long> factors = prime_factors(nums[i]);

        for (long long factor : factors) {
            if (factors_set.count(factor) == 0) {
                vertices += 1;
                factors_set.insert(factor);
            }
        }
    }

    cout << vertices + n << endl;

    return 0;
}