#include <iostream>
#include <vector>

using namespace std;

bool canPayAllAmounts(vector<int>& coinValues) {
    vector<bool> dp(1001, false);
    dp[0] = true;

    for (int value : coinValues) {
        for (int i = value; i <= 1000; i++) {
            if (dp[i - value]) {
                dp[i] = true;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (!dp[i]) {
            return false;
        }
    }

    return true;
}

bool canUseGreedyAlgorithm(vector<int>& coinValues) {
    for (int i = 1; i <= 1000; i++) {
        int remaining = i;
        for (int j = coinValues.size() - 1; j >= 0; j--) {
            int numCoins = remaining / coinValues[j];
            remaining -= numCoins * coinValues[j];
        }
        if (remaining != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    int caseNum = 1;

    while (cin >> n && n != 0) {
        vector<int> coinValues(n);
        for (int i = 0; i < n; i++) {
            cin >> coinValues[i];
        }

        cout << "Case #" << caseNum << ": ";
        if (!canPayAllAmounts(coinValues)) {
            cout << "Cannot pay some amount" << endl;
        } else if (!canUseGreedyAlgorithm(coinValues)) {
            cout << "Cannot use greedy algorithm" << endl;
        } else {
            cout << "OK" << endl;
        }

        caseNum++;
    }

    return 0;
}