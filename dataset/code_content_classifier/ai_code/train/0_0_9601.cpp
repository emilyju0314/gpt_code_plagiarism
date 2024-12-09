#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> swaps(Q);
    for (int i = 0; i < Q; i++) {
        cin >> swaps[i].first >> swaps[i].second;
    }

    bool left_possible = false, right_possible = false;
    for (int i = 0; i < Q; i++) {
        if (swaps[i].first == 1 || swaps[i].second == 1) {
            left_possible = true;
        }
        if (swaps[i].first == N || swaps[i].second == N) {
            right_possible = true;
        }
    }

    int count = 0;
    if (left_possible && right_possible) {
        count = N;
    } else if (left_possible || right_possible) {
        count = N - 1;
    } else {
        count = N - 2;
    }

    cout << count << endl;

    return 0;
}