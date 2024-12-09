#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> initialDance;
    vector<int> remainingDance;

    for (int i = 0; i < M; i++) {
        int Di, Pi;
        cin >> Di >> Pi;
        initialDance.push_back(make_pair(Di, Pi));
    }

    for (int i = 0; i < N - M; i++) {
        int Di;
        cin >> Di;
        remainingDance.push_back(Di);
    }

    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= N; i++) {
        pq.push({0, i});
    }

    for (auto noble : initialDance) {
        pq.push({noble.first, noble.second});
    }

    for (int i = 0; i < N - M; i++) {
        int Di = remainingDance[i];
        auto [goodness, position] = pq.top();
        pq.pop();
        pq.push({Di, position});
    }

    auto [goodness, position] = pq.top();
    cout << goodness << endl;

    return 0;
}