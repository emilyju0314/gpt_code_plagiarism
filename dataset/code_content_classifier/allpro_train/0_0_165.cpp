#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> x(N);
    vector<pair<int, int>> swaps;

    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < N; i++) {
        swaps.push_back({x[i], i});
    }

    sort(swaps.begin(), swaps.end());

    for (int i = 0; i < N && K > 0; i++) {
        if (swaps[i].second != i) {
            swap(x[i], x[swaps[i].second]);
            swaps[x[i]-1].second = i;
            swaps[swaps[i].second].second = swaps[i].second;

            K--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << x[i] << endl;
    }

    return 0;
}