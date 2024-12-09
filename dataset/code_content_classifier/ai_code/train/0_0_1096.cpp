#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Town {
    int open_day;
    int close_day;
};

bool compare(Town a, Town b) {
    return a.open_day < b.open_day;
}

int main() {
    int n;
    cin >> n;

    vector<Town> towns(n);
    for (int i = 0; i < n; i++) {
        cin >> towns[i].open_day >> towns[i].close_day;
    }

    sort(towns.begin(), towns.end(), compare);

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (towns[i].open_day > towns[j].close_day) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_towns = *max_element(dp.begin(), dp.end());
    cout << max_towns << endl;

    return 0;
}