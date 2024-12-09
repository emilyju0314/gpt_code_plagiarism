#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    vector<int> a(n1), b(n2), c(n3), d(n4);
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n3; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n4; i++) {
        cin >> d[i];
    }

    int m1, m2, m3;
    cin >> m1;
    unordered_set<int> badFirstSecondPairs;
    for (int i = 0; i < m1; i++) {
        int x, y;
        cin >> x >> y;
        badFirstSecondPairs.insert((x - 1) * n2 + (y - 1));
    }

    cin >> m2;
    unordered_set<int> badSecondDrinkPairs;
    for (int i = 0; i < m2; i++) {
        int x, y;
        cin >> x >> y;
        badSecondDrinkPairs.insert((x - 1) * n3 + (y - 1));
    }

    cin >> m3;
    unordered_set<int> badDrinkDessertPairs;
    for (int i = 0; i < m3; i++) {
        int x, y;
        cin >> x >> y;
        badDrinkDessertPairs.insert((x - 1) * n4 + (y - 1));
    }

    int minCost = INT_MAX;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < n3; k++) {
                for (int l = 0; l < n4; l++) {
                    if (badFirstSecondPairs.count(i * n2 + j) || badSecondDrinkPairs.count(j * n3 + k) || badDrinkDessertPairs.count(k * n4 + l)) {
                        continue;
                    }
                    minCost = min(minCost, a[i] + b[j] + c[k] + d[l]);
                }
            }
        }
    }

    if (minCost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}