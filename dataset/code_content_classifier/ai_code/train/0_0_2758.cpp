#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> colors(N);
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
    }

    unordered_map<int, vector<int>> color_positions;
    for (int i = 0; i < N; i++) {
        color_positions[colors[i]].push_back(i);
    }

    vector<int> costs(M, 0);

    for (int i = 0; i < M; i++) {
        int cost = 0;
        int j = 0;
        for (int pos : color_positions[i+1]) {
            cost += abs(pos - j);
            j++;
        }
        costs[i] = cost;
    }

    for (int cost : costs) {
        cout << cost << endl;
    }

    return 0;
}