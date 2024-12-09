#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<int> divisors(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int num = i;
        for (int j = 2; j <= sqrt(num); j++) {
            while (num % j == 0) {
                divisors[j]++;
                num /= j;
            }
        }
        if (num > 1) {
            divisors[num]++;
        }
    }

    long long result = 1;
    for (int i = 2; i <= N; i++) {
        result = (result * (divisors[i] + 1)) % MOD;
    }

    cout << result << endl;

    return 0;
}