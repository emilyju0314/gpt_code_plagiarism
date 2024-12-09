#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> towns(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        towns[i] = make_pair(x, y);
    }

    sort(towns.begin(), towns.end());

    int cost = 0;
    for (int i = 1; i < N; i++) {
        cost += min(abs(towns[i].first - towns[i-1].first), abs(towns[i].second - towns[i-1].second));
    }

    cout << cost << endl;

    return 0;
}