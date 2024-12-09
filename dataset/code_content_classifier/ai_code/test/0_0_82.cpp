#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<int> prefix(n, 0);
    for (int i = 1; i < n - 1; i++) {
        prefix[i] = prefix[i - 1] + cost[i + 1] - cost[i - 1] - 2;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        int total_cost = cost[l] - 1 + cost[r] - cost[l+1] - 1 + prefix[r-1] - prefix[l];
        cout << total_cost << endl;
    }

    return 0;
}