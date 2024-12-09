#include <iostream>

using namespace std;

int count_trailing_zeros(long long n) {
    int count = 0;
    while (n % 10 == 0) {
        count++;
        n /= 10;
    }
    return count;
}

long long f(long long n) {
    if (n < 2) {
        return 1;
    } else {
        return n * f(n - 2);
    }
}

int main() {
    long long N;
    cin >> N;

    long long result = f(N);
    int zeros = count_trailing_zeros(result);

    cout << zeros << endl;

    return 0;
}