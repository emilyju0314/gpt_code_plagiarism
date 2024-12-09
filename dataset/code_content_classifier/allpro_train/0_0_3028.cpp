#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<pair<int, int>> items;
    for (int i = 0; i < N; i++) {
        int v, w;
        cin >> v >> w;
        items.push_back({v, w});
    }

    sort(items.begin(), items.end(), [](pair<int, int>& item1, pair<int, int>& item2) {
        return item1.first * item2.second > item2.first * item1.second;
    });

    double total_value = 0.0;

    for (int i = 0; i < N && W > 0; i++) {
        int weight_used = min(W, items[i].second);
        total_value += items[i].first * ((double)weight_used / items[i].second);
        W -= weight_used;
    }

    cout << fixed;
    cout.precision(10);
    cout << total_value << endl;

    return 0;
}