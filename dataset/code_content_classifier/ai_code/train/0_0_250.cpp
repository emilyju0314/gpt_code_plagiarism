#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candy {
    int price;
    int satisfaction;
    int count;
};

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<vector<Candy>> stores(N);
    vector<vector<int>> d(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        stores[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> stores[i][j].price >> stores[i][j].satisfaction >> stores[i][j].count;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> d[i][j];
        }
    }

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(X + 1, vector<int>(Y + 1, 0)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k <= Y; k++) {
                for (int l = 0; l < stores[i].size(); l++) {
                    if (j - stores[i][l].price >= 0 && k - stores[i][l].price >= 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j - stores[i][l].price][k - stores[i][l].price] + stores[i][l].satisfaction);

                        for (int m = 0; m < N; m++) {
                            if (i != m && j - d[i][m] >= 0 && k - d[i][m] >= 0) {
                                dp[m][j][k] = max(dp[m][j][k], dp[i][j - d[i][m]][k - d[i][m]] + stores[i][l].satisfaction);
                            }
                        }
                    }
                }
            }
        }
    }

    int maxSatisfaction = 0;
    for (auto candy : stores[0]) {
        maxSatisfaction = max(maxSatisfaction, dp[0][X][Y]);
    }

    cout << maxSatisfaction << endl;

    return 0;
}