#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<unordered_set<int>> schedules(N);
        vector<int> days(N);
        vector<int> dp(N, 0);

        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            days[i] = M;
            for (int j = 0; j < M; j++) {
                int day;
                cin >> day;
                schedules[i].insert(day);
            }
        }

        dp[0] = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                int cnt = 0;
                for (int day : schedules[i]) {
                    if (schedules[j].find(day) != schedules[j].end()) {
                        cnt++;
                    }
                }
                dp[i] = max(dp[i], dp[j] + (cnt > 0 ? 1 : 0));
            }
        }

        int max_friends = *max_element(dp.begin(), dp.end());
        cout << max_friends << endl;
    }

    return 0;
}