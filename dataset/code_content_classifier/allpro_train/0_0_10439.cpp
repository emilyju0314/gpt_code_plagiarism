#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes;
    for (int num = 2; primes.size() < n; num++) {
        if (is_prime(num)) {
            primes.push_back(num);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << primes[i] << endl;
    }

    return 0;
}