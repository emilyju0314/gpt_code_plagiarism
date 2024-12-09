#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    int num = 2;
    while (N > 0) {
        if (isPrime(num) && num <= 55555) {
            cout << num << " ";
            N--;
        }
        num++;
    }

    return 0;
}