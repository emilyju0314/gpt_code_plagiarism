#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> participants(N);
    for(int i = 0; i < N; i++) {
        int H, P;
        cin >> H >> P;
        participants[i] = make_pair(H, P);
    }
    
    sort(participants.begin(), participants.end());
    
    vector<int> dp(N+1, 0);
    
    for(int i = 0; i < N; i++) {
        for(int j = i; j >= 0; j--) {
            if(participants[i].first <= dp[j]) {
                dp[j+1] = max(dp[j+1], dp[j] + participants[i].second);
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i <= N; i++) {
        res = max(res, dp[i]);
    }
    
    cout << res << endl;
    
    return 0;
}