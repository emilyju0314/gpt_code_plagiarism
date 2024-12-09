#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        long long n, m;
        cin >> n >> m;

        // Calculate the number of pages divisible by m
        long long pages_divisible = n / m;

        // Calculate the sum of digits for each page divisible by m
        long long sum = 0;
        for (int i = 0; i <= 9; i++) {
            sum += pages_divisible / 10 * 10 * i; // Adding multiples of 10s
            if (pages_divisible % 10 >= i) {
                sum += i * (pages_divisible % 10 + 1);
            }
        }

        cout << sum << endl;
    }

    return 0;
}