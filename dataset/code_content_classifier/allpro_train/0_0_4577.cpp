#include <iostream>
#include <vector>

using namespace std;

int cubic(int n) {
    return n * n * n;
}

int tetrahedral(int n) {
    return n * (n + 1) * (n + 2) / 6;
}

int main() {
    vector<int> inputs;

    int num;
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        inputs.push_back(num);
    }

    for (int i = 0; i < inputs.size(); i++) {
        int input = inputs[i];

        if (input <= 0) {
            continue;
        }

        vector<vector<int>> dp(2, vector<int>(input + 1, 0));

        for (int n = 0; cubic(n) <= input; n++) {
            dp[0][cubic(n)] = cubic(n);
        }

        for (int n = 0; tetrahedral(n) <= input; n++) {
            dp[1][tetrahedral(n)] = tetrahedral(n);
        }

        for (int j = 0; j <= input; j++) {
            dp[1][j] = max(dp[1][j], dp[0][j]);
            if (dp[1][j] == 0) {
                dp[1][j] = dp[1][j - 1];
            }
        }

        cout << dp[1][input] << endl;
    }

    return 0;
}