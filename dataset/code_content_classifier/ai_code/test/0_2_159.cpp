#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    vector<int> cnt_prime_factors(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= n; j += i) {
                is_prime[j] = false;
                int tmp = j;
                while (tmp % i == 0) {
                    cnt_prime_factors[j]++;
                    tmp /= i;
                }
            }
        }
    }

    int max_size = 0;
    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (cnt_prime_factors[i] % 2 == 1) {
            max_size++;
            result.push_back(i);
        }
    }

    cout << max_size << endl;
    for (int i = 0; i < max_size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}