#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> chocolates(n);
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    sort(chocolates.begin(), chocolates.end());

    int maxExchanges = 0;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        int curEx = 0;
        int target = chocolates[i] * 2;
        int idx = lower_bound(chocolates.begin(), chocolates.end(), target) - chocolates.begin();
        if (idx < n) {
            curEx = max(curEx, min(chocolates[idx] - chocolates[i], chocolates[i] * 2 - chocolates[idx]));
            if (curEx > maxExchanges) {
                maxExchanges = curEx;
                x = i + 1;
                y = idx + 1;
            }
        }
    }

    cout << x << " " << y << " " << maxExchanges << endl;

    return 0;
}