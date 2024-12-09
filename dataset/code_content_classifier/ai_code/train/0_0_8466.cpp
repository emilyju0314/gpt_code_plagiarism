#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> sushi;
    for (int i = 0; i < N; i++) {
        int t, d;
        cin >> t >> d;
        sushi.push_back(make_pair(d, t));
    }

    sort(sushi.begin(), sushi.end(), greater<pair<int, int>>());

    long long ans = 0;
    long long baseTotalDeliciousness = 0;
    long long varietyBonus = 0;
    vector<int> counts(N + 1, 0);

    for (int i = 0; i < K; i++) {
        baseTotalDeliciousness += sushi[i].first;
        counts[sushi[i].second]++;
    }

    for (int i = 1; i <= N; i++) {
        varietyBonus += counts[i] * counts[i];
    }

    ans = baseTotalDeliciousness + varietyBonus;

    cout << ans << endl;

    return 0;
}