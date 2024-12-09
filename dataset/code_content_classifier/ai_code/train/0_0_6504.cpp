#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    vector<pair<long long, long long>> testCases(t);

    for (int i = 0; i < t; i++) {
        cin >> testCases[i].first >> testCases[i].second;
    }

    for (int i = 0; i < t; i++) {
        long long x = testCases[i].first, y = testCases[i].second;
        if (x - y > 1) {
            cout << "YES" << endl;
        } else {
            if (isPrime(x)) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}