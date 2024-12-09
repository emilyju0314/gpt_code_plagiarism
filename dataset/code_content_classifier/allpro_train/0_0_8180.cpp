#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> bestMoments(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        bestMoments[i] = make_pair(l, r);
    }

    int minute = 1;
    int totalMinutes = 0;
    for (int i = 0; i < n; i++) {
        while (minute + x <= bestMoments[i].first) {
            totalMinutes += x;
            minute += x;
        }
        totalMinutes += bestMoments[i].second - minute + 1;
        minute = bestMoments[i].second + 1;
    }

    cout << totalMinutes << endl;

    return 0;
}