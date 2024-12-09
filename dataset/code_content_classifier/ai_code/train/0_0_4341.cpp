#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h, m;
    cin >> n >> h >> m;

    vector<int> restrictions(n+1, h);
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int j = l; j <= r; j++) {
            restrictions[j] = min(restrictions[j], x); // Update the tallest house height allowed in each spot
        }
    }

    int profit = 0;
    for (int i = 1; i <= n; i++) {
        profit += restrictions[i] * restrictions[i]; // Calculate profit for each spot
    }

    cout << profit << endl;

    return 0;
}