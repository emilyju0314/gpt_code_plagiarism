#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int caseNum = 1;

    while(true) {
        int W, N;
        cin >> W;
        if(W == 0) {
            break;
        }
        cin >> N;

        vector<pair<int, int>> treasures;
        for(int i = 0; i < N; i++) {
            int v, w;
            char comma;
            cin >> v >> comma >> w;
            treasures.push_back({v, w});
        }

        vector<int> dp(W + 1, 0);
        for(int i = 0; i < N; i++) {
            for(int j = W; j >= treasures[i].second; j--) {
                dp[j] = max(dp[j], dp[j - treasures[i].second] + treasures[i].first);
            }
        }

        int totalValue = dp[W];

        int totalWeight = 0;
        for(int i = W; i >= 0; i--) {
            if(dp[i] == totalValue) {
                totalWeight = i;
                break;
            }
        }

        cout << "Case " << caseNum << ":" << endl;
        cout << totalValue << endl;
        cout << totalWeight << endl;

        caseNum++;
    }

    return 0;
}