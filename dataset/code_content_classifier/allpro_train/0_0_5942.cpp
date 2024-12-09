#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, L;
    cin >> n >> L;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    long long cost = 0;
    int currVol = 0;
    for (int i = 0; L > 0; i++) {
        int bottlesNeeded = (L + (1 << i) - 1) / (1 << i);
        int bottlesToBuy = min(bottlesNeeded, (1 << n) - currVol);
        cost += (long long)bottlesToBuy * c[i];
        currVol += bottlesToBuy * (1 << i);
        L -= bottlesToBuy * (1 << i);
    }

    cout << cost << endl;

    return 0;
}