#include <iostream>
#include <cmath>

using namespace std;

bool isT_Prime(long long num) {
    if (num < 4) {
        return false;
    }
    long long root = sqrt(num);
    return root * root == num && is_prime(root);
}

bool is_prime(long long num) {
    if (num < 2) {
        return false;
    }
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        if (isT_Prime(num)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}