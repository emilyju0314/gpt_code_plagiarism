#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long findMinUnrepresentableAmount(int n, int k, vector<int>& denominations) {
    long long s = 1;
    while (true) {
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += (s / pow(10, denominations[i]));
        }
        if (sum > k) {
            return s;
        }
        s++;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> denominations(n);
        for (int j = 0; j < n; j++) {
            cin >> denominations[j];
        }

        cout << findMinUnrepresentableAmount(n, k, denominations) << endl;
    }

    return 0;
}