#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, N;
    cin >> L >> N;

    vector<pair<int, int>> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i].first >> weights[i].second;
    }

    for (int mask = 0; mask < (1 << N); mask++) {
        int total_weight = 0;
        int total_product = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                total_weight += weights[i].second;
                total_product += weights[i].first * weights[i].second;
            }
        }
        if (total_weight * total_product == 0) {
            cout << __builtin_popcount(mask) << endl;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    cout << weights[i].first << " " << weights[i].second << endl;
                }
            }
            break;
        }
    }

    return 0;
}