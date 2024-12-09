#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int sign = 1;
    long long result = 0;
    for(int i = 0; i < n; i++) {
        long long num = (n - i) * (n - i);
        num %= mod;

        result = (result + num * sign * numbers[i]) % mod;
        sign *= -1;
    }

    result = (result + mod) % mod;
    cout << result << endl;

    return 0;
}