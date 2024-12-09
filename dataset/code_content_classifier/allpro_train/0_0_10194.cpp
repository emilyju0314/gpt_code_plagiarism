#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    int current_prime = 2;
    for (int i = 0; i < n; i++) {
        while (!is_prime(current_prime)) {
            current_prime++;
        }
        if (current_prime < a[i]) {
            b[i] = a[i];
        } else {
            b[i] = current_prime++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}