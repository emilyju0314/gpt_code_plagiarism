#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPairs(int n) {
    int count = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int num;
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        cout << countPairs(num) << endl;
    }
    return 0;
}