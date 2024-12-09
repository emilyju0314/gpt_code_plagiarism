#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> rectangles(N);

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        rectangles[i] = make_pair(l, r);
    }

    sort(rectangles.begin(), rectangles.end());

    long long total_cost = 0;
    for (int i = N - 1; i > 0; i--) {
        int diff = rectangles[i].first - rectangles[i - 1].second;
        if (diff > 0) {
            rectangles[i].first -= diff;
            total_cost += diff;
        }
    }

    cout << total_cost << endl;

    return 0;
}