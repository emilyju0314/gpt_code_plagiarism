#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;

void SieveOfEratosthenes(int n) {
    bool primeMark[n + 1];
    memset(primeMark, true, sizeof(primeMark));

    for (int p = 2; p * p <= n; p++) {
        if (primeMark[p] == true) {
            for (int i = p * p; i <= n; i += p)
                primeMark[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (primeMark[p]) {
            prime.push_back(p);
        }
    }
}

void findDivisors(int n) {
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < prime.size(); j++) {
            if (a % prime[j] == 0) {
                int d1 = prime[j];
                int d2 = a / prime[j];
                if (d1 != d2) {
                    cout << d1 << " " << d2 << " ";
                    break;
                }
            }
        }
        if (a == 2 || a == 3 || a == 5) {
            cout << "-1 -1 ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    int limit = 30000;
    SieveOfEratosthenes(limit);

    findDivisors(n);

    return 0;
}