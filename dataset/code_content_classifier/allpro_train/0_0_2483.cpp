#include <iostream>

using namespace std;

long long sum_of_digits(long long num) {
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    long long n, s;
    cin >> n >> s;

    long long count = 0;
    for (long long i = 1; i <= n; i++) {
        if (i - sum_of_digits(i) >= s) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}