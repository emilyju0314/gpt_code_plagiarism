#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(int n, vector<int>& weights, string& sides) {
    vector<pair<int, int>> sortedWeights;
    for (int i = 0; i < n; i++) {
        sortedWeights.push_back({weights[i], i});
    }

    sort(sortedWeights.begin(), sortedWeights.end());

    int leftIdx = n-1, rightIdx = 0;
    for (int i = 0; i < n; i++) {
        int weight = sortedWeights[i].first;
        int idx = sortedWeights[i].second;

        if (sides[idx] == 'L') {
            cout << weight << " L" << endl;
            leftIdx--;
        } else {
            cout << weight << " R" << endl;
            rightIdx++;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    string sides;
    cin >> sides;

    if (!solve(n, weights, sides)) {
        cout << -1 << endl;
    }

    return 0;
}