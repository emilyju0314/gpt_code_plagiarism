#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Program {
    string title;
    string startTime;
    string endTime;
    int onAirScore;
    int recordedScore;
};

bool compare(Program p1, Program p2) {
    return p1.endTime < p2.endTime;
}

int main() {
    int N;
    
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        vector<Program> programs(N);
        for (int i = 0; i < N; i++) {
            cin >> programs[i].title >> programs[i].startTime >> programs[i].endTime >> programs[i].onAirScore >> programs[i].recordedScore;
        }
        
        sort(programs.begin(), programs.end(), compare);
        
        vector<int> dp(N+1, 0);
        
        for (int i = 1; i <= N; i++) {
            dp[i] = max(dp[i-1], dp[i]);
            int curScore = programs[i-1].onAirScore;
            for (int j = i-1; j >= 0; j--) {
                if (programs[j].endTime <= programs[i-1].startTime) {
                    curScore += programs[j].recordedScore;
                    dp[i] = max(dp[i], dp[j] + curScore);
                    break;
                }
            }
        }
        
        cout << dp[N] << endl;
    }
    
    return 0;
}