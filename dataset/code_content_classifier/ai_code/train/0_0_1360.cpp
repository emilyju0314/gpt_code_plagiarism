#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    vector<pair<int, int>> totalHappiness;
    for (int i = 0; i < N; i++) {
        int si, ai, bi;
        cin >> si >> ai >> bi;
        totalHappiness.push_back({si, si * ai + si * bi});
    }

    sort(totalHappiness.begin(), totalHappiness.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    long long ans = 0;
    int slicesLeft = N * S;
    for (int i = 0; i < N; i++) {
        int maxSlices = min(slicesLeft, totalHappiness[i].first);
        ans += maxSlices * totalHappiness[i].second;
        slicesLeft -= maxSlices;
    }

    cout << ans << endl;

    return 0;
}