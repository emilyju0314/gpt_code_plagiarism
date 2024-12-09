#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> users(n);
    for (int i = 0; i < n; i++) {
        cin >> users[i].first >> users[i].second;
    }

    sort(users.begin(), users.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    int max_b = users[0].second;
    vector<int> profits(max_b + 2, 0);

    int curr_profit = 0;
    for (int i = 0; i < n; i++) {
        curr_profit += users[i].second * w;
        profits[users[i].second] = max(profits[users[i].second], curr_profit);
    }

    for (int i = 1; i <= max_b; i++) {
        profits[i] = max(profits[i], profits[i-1]);
    }

    int max_p = 0;
    for (int i = 0; i <= max_b + 1; i++) {
        cout << i << " " << profits[i] << endl;
        if (profits[i] > max_p) {
            max_p = profits[i];
        }
    }

    return 0;
}