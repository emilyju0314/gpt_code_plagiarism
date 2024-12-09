#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool canReach(vector<int>& pos, vector<int>& target, string& instructions) {
    vector<vector<bool>> dp(2, vector<bool>(8001, false));
    int offset = 4000;

    dp[0][offset] = true;

    int step = 0;
    for (char c : instructions) {
        dp[1 - step] = vector<bool>(8001, false);
        int diff = (c == 'F') ? 1 : 0;
        
        for (int i = 0; i < 8001; i++) {
            if (!dp[step][i]) continue;
            if (i + diff <= 8000) dp[1 - step][i + diff] = true;
            if (i - diff >= 0) dp[1 - step][i - diff] = true;
        }
        
        step = 1 - step;
    }

    return dp[step][offset + target[0]] && dp[step][offset + target[1]];
}

int main() {
    string instructions;
    getline(cin, instructions);

    string targetStr;
    getline(cin, targetStr);
    stringstream ss(targetStr);

    vector<int> target(2);
    ss >> target[0] >> target[1];

    vector<int> pos = {0, 0};

    bool result = canReach(pos, target, instructions);

    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}