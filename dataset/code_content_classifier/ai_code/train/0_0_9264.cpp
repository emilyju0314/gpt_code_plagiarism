#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, d;
    cin >> N >> d;

    vector<int> rewards(N);
    for (int i = 0; i < N; i++) {
        cin >> rewards[i];
    }

    int max_reward = 0;
    for (int i = 0; i < N; i++) {
        int current_reward = 0;
        int current_station = i;
        vector<bool> visited(N, false);

        while (!visited[current_station]) {
            visited[current_station] = true;
            current_reward += rewards[current_station];
            current_station = (current_station + d) % N;
        }

        max_reward = max(max_reward, current_reward);
    }

    if (max_reward <= 1) {
        cout << "kusoge" << endl;
    } else {
        cout << max_reward << endl;
    }

    return 0;
}