#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int t, d, p;
};

bool compareItems(Item& a, Item& b) {
    return a.d < b.d;
}

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].t >> items[i].d >> items[i].p;
    }

    sort(items.begin(), items.end(), compareItems);

    vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
    vector<vector<int>> path(n + 1, vector<int>(2001, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2000; j++) {
            dp[i][j] = dp[i - 1][j];
            path[i][j] = j;
            if (j >= items[i - 1].d) {
                continue;
            }
            int saveValue = dp[i - 1][j - items[i - 1].t] + items[i - 1].p;
            if (saveValue > dp[i][j]) {
                dp[i][j] = saveValue;
                path[i][j] = j - items[i - 1].t;
            }
        }
    }

    int maxValue = 0;
    int maxIndex = -1;
    for (int i = 0; i <= 2000; i++) {
        if (dp[n][i] > maxValue) {
            maxValue = dp[n][i];
            maxIndex = i;
        }
    }

    cout << maxValue << endl;

    vector<int> result;
    for (int i = n; i > 0; i--) {
        if (path[i][maxIndex] != maxIndex) {
            result.push_back(i);
        }
        maxIndex = path[i][maxIndex];
    }

    cout << result.size() << endl;
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }

    return 0;
}