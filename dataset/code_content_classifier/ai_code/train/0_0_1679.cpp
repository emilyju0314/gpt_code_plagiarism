#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<long long, int> factorize(long long num) {
    unordered_map<long long, int> factors;
    for (long long i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            factors[i]++;
            num /= i;
        }
    }
    if (num > 1) {
        factors[num]++;
    }
    return factors;
}

int main() {
    int n;
    cin >> n;

    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    unordered_map<long long, int> primeFactorsCount;
    for (long long num : numbers) {
        unordered_map<long long, int> factors = factorize(num);
        for (auto factor : factors) {
            primeFactorsCount[factor.first] = max(primeFactorsCount[factor.first], factor.second);
        }
    }

    int minVertices = 0;
    for (auto factor : primeFactorsCount) {
        minVertices += factor.second;
    }

    cout << minVertices << endl;

    return 0;
}