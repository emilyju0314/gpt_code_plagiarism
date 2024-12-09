#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int power(int x, int y) {
    int result = 1;
    x %= MOD;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % MOD;
        }
        y = y / 2;
        x = (x * x) % MOD;
    }
    return result;
}

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    unordered_map<vector<int>, int> freq;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vector<int> colors = {ax + i, ay + j, bx + i, by + j};
            sort(colors.begin(), colors.end());
            freq[colors]++;
        }
    }

    long long result = 1;
    for (auto entry : freq) {
        result = (result * power(k, entry.second)) % MOD;
    }

    cout << result << endl;

    return 0;
}