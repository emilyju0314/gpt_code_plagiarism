#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> chocolates;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        chocolates.emplace_back(a, i+1);
    }

    sort(chocolates.rbegin(), chocolates.rend());

    int x = chocolates[0].second;
    int y = chocolates[1].second;

    int m = 0;
    for (int k = 0; k <= 30; k++) {
        int target = chocolates[0].first + (1 << k);
        if (binary_search(chocolates.begin(), chocolates.end(), make_pair(target, -1))) {
            m = k;
            break;
        }
    }

    cout << x << " " << y << " " << m << endl;

    return 0;
}