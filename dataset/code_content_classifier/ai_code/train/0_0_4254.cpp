#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<set<int>> days(m);
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int store;
            cin >> store;
            days[i].insert(store);
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<int> divisors;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                divisors.push_back(j);
                if (j * j != i) {
                    divisors.push_back(i / j);
                }
            }
        }

        bool possible = true;
        for (int j = 0; j < m; j++) {
            bool found = false;
            for (int store : days[j]) {
                if (lcm(i, store) == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "possible" << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;

    return 0;
}