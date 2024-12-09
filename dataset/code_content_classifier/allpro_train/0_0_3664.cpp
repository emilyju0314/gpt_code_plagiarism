#include <iostream>
#include <vector>
#include <algorithm>

#define MOD (int)1e9 + 7

using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> firstRow(n), secondRow(n);
        for (int i = 0; i < n; i++) {
            cin >> firstRow[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> secondRow[i];
        }

        int diff = 0;
        vector<int> numCount(n+1, 0);
        for (int i = 0; i < n; i++) {
            if (firstRow[i] != secondRow[i]) {
                diff++;
            }
            numCount[firstRow[i]]++;
            numCount[secondRow[i]]++;
        }

        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * factorial(numCount[i])) % MOD;
        }

        cout << diff + 1 << endl;
    }

    return 0;
}