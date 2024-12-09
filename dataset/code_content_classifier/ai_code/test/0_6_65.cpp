#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> weights; // pair of weight and its index
    for (int i = 0; i < N; i++) {
        int weight;
        cin >> weight;
        weights.push_back({weight, i});
    }

    string S;
    cin >> S;

    sort(weights.begin(), weights.end()); // sort weights in ascending order

    vector<pair<int, char>> result(N); // pair of weight and balance side
    vector<int> left, right; // weights on the left and right side of the balance

    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            if (left.empty() || weights[i].first > left.back()) {
                result[weights[i].second] = {weights[i].first, 'L'};
                left.push_back(weights[i].first);
            } else {
                cout << -1 << endl;
                return 0;
            }
        } else {
            if (right.empty() || weights[i].first > right.back()) {
                result[weights[i].second] = {weights[i].first, 'R'};
                right.push_back(weights[i].first);
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}