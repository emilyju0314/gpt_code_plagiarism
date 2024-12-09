#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> ages(n);
    vector<int> primes;
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    for (int i = 2; i <= 50; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    bool possible = false;
    vector<vector<int>> tables;
    for (int i = 0; i < primes.size(); i++) {
        vector<int> table;
        bool valid = true;
        for (int j = 0; j < n; j++) {
            if (table.size() < 3 || isPrime(primes[i] + ages[j])) {
                table.push_back(j+1);
            } else {
                valid = false;
                break;
            }
        }
        if (valid) {
            possible = true;
            tables.push_back(table);
        }
    }

    if (!possible) {
        cout << "Impossible" << endl;
    } else {
        cout << tables.size() << endl;
        for (int i = 0; i < tables.size(); i++) {
            cout << tables[i].size() << " ";
            for (int j = 0; j < tables[i].size(); j++) {
                cout << tables[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}