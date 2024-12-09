#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i].first;
        weights[i].second = i;
    }

    string S;
    cin >> S;

    sort(weights.begin(), weights.end());

    int left = -1, right = -1;
    for (int i = 0, j = N - 1; i <= j; ) {
        if (S[i] == 'L') {
            cout << weights[i].first << " L" << endl;
            left = weights[i].second;
            i++;
        } else {
            cout << weights[j].first << " R" << endl;
            right = weights[j].second;
            j--;
        }
    }

    if (left != -1 && right != -1) {
        return 0;
    } else {
        cout << -1 << endl;
        return 0;
    }
}