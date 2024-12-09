#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int W, H;
        cin >> W >> H;

        vector<vector<int>> reserve(H, vector<int>(W));

        for(int j = 0; j < H; j++) {
            for(int k = 0; k < W; k++) {
                cin >> reserve[j][k];
            }
        }

        int dp[H][W];
        dp[0][0] = reserve[0][0];

        for(int j = 0; j < H; j++) {
            for(int k = 0; k < W; k++) {
                if(j == 0 && k == 0) continue;

                int left = (k - 1 >= 0) ? dp[j][k-1] : 0;
                int top = (j - 1 >= 0) ? dp[j-1][k] : 0;
                int topLeft = (j - 1 >= 0 && k - 1 >= 0) ? dp[j-1][k-1] : 0;

                dp[j][k] = max(left, max(top, topLeft)) + reserve[j][k];
            }
        }

        cout << "Case " << i+1 << ": " << dp[H-1][W-1] << endl;
    }

    return 0;
}