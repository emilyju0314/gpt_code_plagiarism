#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> yokans(N);
    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        yokans[i] = make_pair(L, R);
    }

    sort(yokans.begin(), yokans.end());

    int distance = 0;
    int currentPos = 0;

    for (int i = 0; i < N; i++) {
        // Move to the beginning of the current yokan
        if (currentPos <= yokans[i].first) {
            distance += yokans[i].first - currentPos;
            currentPos = yokans[i].first;
        } else if (currentPos >= yokans[i].second) {
            distance += currentPos - yokans[i].second;
            currentPos = yokans[i].second;
        }

        // Eat the yokan
        distance += yokans[i].second - yokans[i].first;
        currentPos = yokans[i].second;
    }

    // Move back to 0
    distance += currentPos;

    cout << distance << endl;

    return 0;
}