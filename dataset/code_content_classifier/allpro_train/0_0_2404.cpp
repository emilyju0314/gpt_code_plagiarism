#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> cities(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<int> reachable(N);
    for (int i = 0; i < N; i++) {
        reachable[i] = 1;
        for (int j = 0; j < i; j++) {
            if (cities[j].first < cities[i].first && cities[j].second < cities[i].second) {
                reachable[i] = max(reachable[i], reachable[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << reachable[i] << endl;
    }

    return 0;
}