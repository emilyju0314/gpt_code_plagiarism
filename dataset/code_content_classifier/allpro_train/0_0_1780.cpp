#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int ti, td, tr, te;
    cin >> ti >> td >> tr >> te;

    string A, B;
    cin >> A;
    cin >> B;

    int lenA = A.length();
    int lenB = B.length();

    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));

    for (int i = 0; i <= lenA; i++) {
        for (int j = 0; j <= lenB; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                dp[i][j] = j * ti;
            } else if (j == 0) {
                dp[i][j] = i * td;
            } else {
                int cost = (A[i-1] == B[j-1] ? 0 : tr);
                dp[i][j] = min({dp[i-1][j-1] + cost, dp[i-1][j] + td, dp[i][j-1] + ti});

                if (i > 1 && j > 1 && A[i-1] == B[j-2] && A[i-2] == B[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-2][j-2] + te);
                }
            }
        }
    }

    cout << dp[lenA][lenB] << endl;

    return 0;
}