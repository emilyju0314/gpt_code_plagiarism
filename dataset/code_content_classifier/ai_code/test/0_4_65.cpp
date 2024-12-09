#include <iostream>
#include <vector>

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
    vector<int> left, right;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            left.push_back(weights[i]);
        } else {
            right.push_back(weights[i]);
        }
    }

    // Sorting according to given rules
    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), greater<int>());

    for (int i = 0, j = 0, k = 0; i < N; i++) {
        if (S[i] == 'L') {
            result.push_back(make_pair(left[j], 'L'));
            j++;
        } else {
            result.push_back(make_pair(right[k], 'R'));
            k++;
        }
    }

    bool valid = true;
    for (int i = 0; i < N - 1; i++) {
        if ((S[i] == 'L' && result[i].first > result[i+1].first) || 
            (S[i] == 'R' && result[i].first < result[i+1].first)) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "-1" << endl;
    } else {
        for (auto p : result) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}