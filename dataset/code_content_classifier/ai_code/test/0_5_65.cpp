#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> weights;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        weights.push_back({w, i});
    }

    string s;
    cin >> s;

    sort(weights.begin(), weights.end());

    stack<pair<int, int>> left, right;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            left.push(weights[i]);
        } else {
            right.push(weights[i]);
        }
    }

    while (!left.empty() && !right.empty()) {
        cout << left.top().first << " L" << endl;
        cout << right.top().first << " R" << endl;
        left.pop();
        right.pop();
    }

    if (!left.empty() || !right.empty()) {
        cout << -1 << endl;
    }

    return 0;
}