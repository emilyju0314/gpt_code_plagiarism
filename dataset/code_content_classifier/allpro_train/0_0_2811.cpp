#include <iostream>
using namespace std;

int primesCount(int n) {
    if (n < 2) return 0;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    int count = 0;
    for (int p = 2; p <= n; p++) {
        if (prime[p]) count++;
    }
    return count;
}

int isPalindrome(int n) {
    int rev = 0, num = n;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return n == rev;
}

int palindromicCount(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (isPalindrome(i)) count++;
    }
    return count;
}

int main() {
    int p, q;
    cin >> p >> q;
    double A = (double)p / q;
    int n = 2;
    while (primesCount(n) <= A * palindromicCount(n)) {
        n++;
    }
    if (n > 2) {
        cout << n-1 << endl;
    } else {
        cout << "Palindromic tree is better than splay tree" << endl;
    }
    return 0;
}