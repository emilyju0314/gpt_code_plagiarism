#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int countDivisors(int n) {
    int divisors = 1;
    vector<int> factors = getPrimeFactors(n);
    int prev = -1;
    int count = 0;
    for (int factor : factors) {
        if (factor == prev) {
            count++;
        } else {
            divisors *= (count + 1);
            prev = factor;
            count = 1;
        }
    }
    divisors *= (count + 1);
    return divisors;
}

int minOperations(int a, int b) {
    int divisors_a = countDivisors(a);
    int divisors_b = countDivisors(b);

    if (divisors_a == divisors_b) {
        return 0;
    }

    if (divisors_a < divisors_b) {
        swap(divisors_a, divisors_b);
        swap(a, b);
    }

    int diff = divisors_a - divisors_b;
    int ans = 0;
    for (int i = 2; i * i <= diff; i++) {
        while (diff % i == 0 && a % i == 0) {
            diff /= i;
            a /= i;
            ans++;
        }
    }

    if (diff > 1 && a % diff == 0) {
        ans++;
    }
    if (a > 1 && b % a == 0) {
        ans++;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << minOperations(a, b) << endl;
    }

    return 0;
}