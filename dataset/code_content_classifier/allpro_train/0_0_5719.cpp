#include <iostream>
#include <string>

using namespace std;

int sumOfDigits(long long num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    long long n;
    cin >> n;

    long long half = n / 2;
    string str_n = to_string(n);
    string str_half = to_string(half);

    if (str_half.length() < str_n.length()) {
        half++;
    }

    long long a = half;
    long long b = n - half;

    cout << sumOfDigits(a) + sumOfDigits(b) << endl;

    return 0;
}