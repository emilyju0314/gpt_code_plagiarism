#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, h, m;
    cin >> n >> h >> m;

    vector<int> heights(n, h);
    vector<int> fines(n, 0);

    for (int i = 0; i < m; i++) {
        int l, r, x, c;
        cin >> l >> r >> x >> c;
        for (int j = l-1; j <= r-1; j++) {
            heights[j] = min(heights[j], x);
            fines[j] = max(fines[j], c);
        }
    }

    long long profit = 0;
    for (int i = 0; i < n; i++) {
        profit += heights[i] * heights[i];
        profit -= fines[i];
    }

    cout << profit << endl;

    return 0;
}