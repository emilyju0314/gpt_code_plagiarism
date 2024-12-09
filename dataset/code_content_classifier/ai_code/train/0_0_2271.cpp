#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int query(long long Q) {
    cout << "? " << Q << endl;
    cout.flush();

    int response;
    cin >> response;

    return response;
}

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        long long X = 1;
        int num_divisors = 1;

        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        for (int p : primes) {
            long long power = 1;
            while (true) {
                long long next_X = X * power;

                if (next_X > 1e9) break;

                if (query(next_X) > 1) {
                    X = next_X;
                    num_divisors *= 2;
                }

                power *= p;
            }
        }

        for (int i = 31; i <= 50; i++) {
            long long next_X = X * i;
            if (next_X > 1e9) break;

            if (query(next_X) > 1) {
                X = next_X;
                num_divisors *= 2;
            }
        }

        for (int i = 4; i <= sqrt(X); i++) {
            if (X % i == 0) {
                long long next_X = X * i;
                if (next_X <= 1e9 && query(next_X) > 1) {
                    X = next_X;
                    num_divisors *= 2;
                }
            }
        }

        if (!is_prime(X)) num_divisors *= 2;

        cout << "! " << num_divisors << endl;
        cout.flush();
    }
    
    return 0;
}