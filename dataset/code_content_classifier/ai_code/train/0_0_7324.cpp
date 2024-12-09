#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ring {
    int innerRadius;
    int outerRadius;
    int height;
};

bool compareRings(const Ring& r1, const Ring& r2) {
    return r1.outerRadius > r2.outerRadius;
}

int main() {
    int n;
    cin >> n;

    vector<Ring> rings(n);
    for (int i = 0; i < n; i++) {
        cin >> rings[i].innerRadius >> rings[i].outerRadius >> rings[i].height;
    }

    sort(rings.begin(), rings.end(), compareRings);

    vector<long long> dp(n);
    dp[0] = rings[0].height;

    long long maxHeight = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = rings[i].height;
        for (int j = 0; j < i; j++) {
            if (rings[j].outerRadius > rings[i].innerRadius) {
                dp[i] = max(dp[i], dp[j] + rings[i].height);
            }
        }
        maxHeight = max(maxHeight, dp[i]);
    }

    cout << maxHeight << endl;

    return 0;
}