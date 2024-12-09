#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canCoexist(string word, vector<string>& religions) {
    vector<vector<int>> dp(3, vector<int>(word.size()+1, 0));

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= word.size(); j++) {
            if (religions[i].back() == word[j-1]) {
                dp[i][j] = dp[i][j-1] + 1;
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    if (dp[0][word.size()] == religions[0].size() && dp[1][word.size()] == religions[1].size() && dp[2][word.size()] == religions[2].size()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    string word;
    cin >> word;

    vector<string> religions(3, "");
    
    for (int i = 0; i < q; i++) {
        char op;
        int rel;
        cin >> op >> rel;

        if (op == '+') {
            char c;
            cin >> c;
            religions[rel-1] += c;
        } else {
            religions[rel-1].pop_back();
        }

        if (canCoexist(word, religions)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}