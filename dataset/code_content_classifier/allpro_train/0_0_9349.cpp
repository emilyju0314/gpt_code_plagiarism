#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Date {
    int start, end;
};

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<vector<Date>> dates(N);
        vector<int> satisfaction(N);

        for (int i = 0; i < N; i++) {
            int M, L;
            cin >> M >> L;
            satisfaction[i] = L;
            
            for (int j = 0; j < M; j++) {
                int start, end;
                cin >> start >> end;
                dates[i].push_back({start, end});
            }
        }

        vector<int> dp(23, 0); // dp[i] stores the maximum satisfaction at time i

        for (int i = 6; i <= 22; i++) {
            dp[i] = dp[i - 1]; // carry over the maximum satisfaction from the previous time
            for (int j = 0; j < N; j++) {
                int curr_satisfaction = 0;
                for (auto date : dates[j]) {
                    if (date.start <= i && i < date.end) {
                        curr_satisfaction += satisfaction[j];
                        break;
                    }
                }
                dp[i] = max(dp[i], dp[date.start] + curr_satisfaction);
            }
        }

        cout << dp[22] << endl;
    }

    return 0;
}