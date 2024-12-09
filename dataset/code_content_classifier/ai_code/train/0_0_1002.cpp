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

int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    return count;
}

int D(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (countDivisors(i) == 4) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << D(n) << endl;
    return 0;
}