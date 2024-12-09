#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long x, y, l, r;
    cin >> x >> y >> l >> r;

    vector<long long> unluckyYears;
    unluckyYears.push_back(l - 1);
    unluckyYears.push_back(r + 1);

    long long cur = 1;
    while (cur <= r) {
        if (cur < l) {
            unluckyYears.push_back(cur);
        }
        cur *= x;
    }

    cur = 1;
    while (cur <= r) {
        if (cur < l) {
            unluckyYears.push_back(cur);
        }
        cur *= y;
    }

    sort(unluckyYears.begin(), unluckyYears.end());

    long long maxGap = 0;
    for (int i = 1; i < unluckyYears.size(); i++) {
        maxGap = max(maxGap, unluckyYears[i] - unluckyYears[i-1] - 1);
    }

    cout << maxGap << endl;

    return 0;
}