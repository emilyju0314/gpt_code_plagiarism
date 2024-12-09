#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, x, pos;
    cin >> n >> x >> pos;

    int left = 0, right = n;
    int less = 0, greater = 0;

    while (left < right) {
        int mid = (left + right) / 2;
        if (mid < pos) {
            less++;
            left = mid + 1;
        }
        else if (mid > pos) {
            greater++;
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    int equal = n - less - greater - 1;

    int less_ways = x > pos ? less : less - 1;
    int greater_ways = x < pos ? greater : greater - 1;

    long long result = 1;
    for (int i = n - 1; i > equal; i--) {
        result = (result * i) % MOD;
    }
    result = (result * power(n - equal - 1, less_ways)) % MOD;
    result = (result * power(n - equal - 1 - less_ways, greater_ways)) % MOD;

    cout << result << endl;

    return 0;
}