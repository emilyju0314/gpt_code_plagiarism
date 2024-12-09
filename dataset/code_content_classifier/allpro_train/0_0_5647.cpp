#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    vector<int> goodIntegers;

    for (int x = 1; x <= n; x++) {
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j] <= x) {
                    f[i]++;
                }
            }
        }
        int result = 1;
        for (int i = 0; i < n; i++) {
            result *= (f[i] - i);
        }
        if (result % p != 0) {
            count++;
            goodIntegers.push_back(x);
        }
    }

    cout << count << endl;
    for (int i = 0; i < goodIntegers.size(); i++) {
        cout << goodIntegers[i] << " ";
    }
    cout << endl;

    return 0;
}