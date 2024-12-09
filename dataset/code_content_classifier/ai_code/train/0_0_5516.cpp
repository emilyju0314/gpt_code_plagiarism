#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> moves(n);
    for (int i = 0; i < n; i++) {
        cin >> moves[i].first >> moves[i].second;
    }

    long long max_distance = 1.5e6;
    vector<int> signs(n, 1);
    long long x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        if (abs(x + moves[i].first) <= max_distance) {
            x += moves[i].first;
        } else {
            x -= moves[i].first;
            signs[i] = -1;
        }
        if (abs(y + moves[i].second) <= max_distance) {
            y += moves[i].second;
        } else {
            y -= moves[i].second;
            signs[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << signs[i] << " ";
    }

    return 0;
}