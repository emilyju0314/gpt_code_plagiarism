#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    if (x <= y) {
        cout << n * x << endl;
    } else {
        int maxGCD = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxGCD = max(maxGCD, gcd(numbers[i], numbers[j]));
            }
        }

        // If the list is already good
        if (maxGCD > 1) {
            cout << 0 << endl;
        } else {
            int minCost = y;
            for (int i = 0; i < n; i++) {
                if (numbers[i] % x == 0) {
                    minCost = min(minCost, x);
                } else {
                    minCost = min(minCost, x + y - numbers[i] % x);
                }
            }

            cout << minCost << endl;
        }
    }

    return 0;
}