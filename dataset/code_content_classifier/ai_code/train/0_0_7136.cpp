#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int min_actions = 0;
    vector<pair<char, pair<int, int>>> actions;

    for (int i = 1; i < n; i++) {
        int diff = heights[i] - heights[i-1] - k;

        if (diff > 0) {
            heights[i-1] += diff;
            actions.push_back({'+', {i, diff}});
            min_actions += ceil((double)diff / k);
        } else if (diff < 0) {
            heights[i] += abs(diff);
            actions.push_back({'-', {i+1, abs(diff)}});
            min_actions += ceil((double)abs(diff) / k);
        }
    }

    cout << min_actions << endl;
    for (auto action : actions) {
        cout << action.first << " " << action.second.first << " " << action.second.second << endl;
    }

    return 0;
}