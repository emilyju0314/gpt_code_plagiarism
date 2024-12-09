#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);

    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        int h = heights[i];
        for(int j = i + 1; j < n; j++) {
            h = min(h, heights[j]);
            ans = (ans + h) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}