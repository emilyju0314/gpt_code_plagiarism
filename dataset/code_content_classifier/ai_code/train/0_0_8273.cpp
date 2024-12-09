#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minCost = INT_MAX;
    for (int i = 0; i < 3; i++) {
        int cost = 0;
        vector<int> tempArr = arr;

        for (int j = i; j < n; j += 3) {
            if (tempArr[j] % 2 == 0) {
                continue; // no change needed
            }

            int diff1 = tempArr[j] % 2;
            int diff2 = 2 - diff1;
            cost += min(diff1 * a, diff2 * b);
            tempArr[j] += diff2;
        }

        int gc = tempArr[0];
        for (int j = 1; j < n; j++) {
            gc = gcd(gc, tempArr[j]);
        }

        if (gc > 1) {
            minCost = min(minCost, cost);
        }
    }

    cout << minCost << endl;

    return 0;
}