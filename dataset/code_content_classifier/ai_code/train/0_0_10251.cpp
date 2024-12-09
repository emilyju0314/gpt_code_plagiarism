#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    long long n;
    cin >> n;

    for(int i = 1; i <= 81; i++) {
        long long x = n - i + sumOfDigits(i);
        if(x > 0 && sumOfDigits(x) == i && x * sumOfDigits(i) == n) {
            cout << x << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}