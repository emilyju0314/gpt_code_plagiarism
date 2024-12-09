#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve(int n) {
    if (n < 31) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    
    if (n == 36) {
        cout << "5 6 10 15" << endl;
    } else if (n == 44) {
        cout << "6 7 10 21" << endl;
    } else if (n == 40) {
        cout << "6 10 11 13" << endl;
    } else {
        cout << "6 10 14 " << n - 30 << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        solve(n);
    }

    return 0;
}