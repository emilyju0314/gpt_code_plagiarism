#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<queue<int>> lanes(N);
    queue<int> entrance_order;

    for (int i = 0; i < M; i++) {
        int type, info;
        cin >> type >> info;

        if (type == 0) {
            cout << entrance_order.front() << endl;
            entrance_order.pop();
            continue;
        }

        entrance_order.push(info);
        int min_len = INT_MAX;
        int min_lane = -1;
        for (int j = 0; j < N; j++) {
            if (lanes[j].size() < min_len || (lanes[j].size() == min_len && j < min_lane)) {
                min_len = lanes[j].size();
                min_lane = j;
            }
        }

        lanes[min_lane].push(info);
    }

    return 0;
}