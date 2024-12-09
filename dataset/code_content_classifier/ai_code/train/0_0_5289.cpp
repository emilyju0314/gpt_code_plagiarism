#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFinishContest(vector<long long>& initialCharge, vector<int>& powerUsage, long long power, int k) {
    long long totalPower = 0, extraPower = 0;
    for (int i = 0; i < initialCharge.size(); i++) {
        totalPower += initialCharge[i];
        extraPower += min(0LL, totalPower - 1LL*power*k);
        totalPower -= min(totalPower, 1LL*power*k);
        if (totalPower < 0) return false;
    }
    return extraPower >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> initialCharge(n);
    vector<int> powerUsage(n);

    for (int i = 0; i < n; i++) {
        cin >> initialCharge[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> powerUsage[i];
    }

    long long low = 0, high = *max_element(powerUsage.begin(), powerUsage.end()) * k;
    long long ans = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canFinishContest(initialCharge, powerUsage, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}