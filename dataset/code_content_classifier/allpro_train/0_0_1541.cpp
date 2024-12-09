#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> robots(N);
    vector<int> exits(M);

    for (int i = 0; i < N; i++) {
        cin >> robots[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> exits[i];
    }

    long long total_combinations = 1;

    int robot_index = 0;
    int exit_index = 0;

    while (robot_index < N && exit_index < M) {
        if (robots[robot_index] <= exits[exit_index]) {
            total_combinations = (total_combinations * (M - exit_index)) % MOD;
            robot_index++;
        } else {
            exit_index++;
        }
    }

    cout << total_combinations << endl;

    return 0;
}