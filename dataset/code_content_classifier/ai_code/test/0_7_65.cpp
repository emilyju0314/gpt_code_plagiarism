#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    string S;
    cin >> S;

    vector<pair<int, char>> result;
    vector<int> left_weights, right_weights;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            left_weights.push_back(weights[i]);
        } else {
            right_weights.push_back(weights[i]);
        }

        if (left_weights.size() > right_weights.size()) {
            result.push_back({left_weights.back(), 'L'});
            left_weights.pop_back();
        } else {
            result.push_back({right_weights.back(), 'R'});
            right_weights.pop_back();
        }
    }

    if (left_weights.size() != right_weights.size()) {
        cout << -1 << endl;
    } else {
        for (auto val : result) {
            cout << val.first << " " << val.second << endl;
        }
    }

    return 0;
}