#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSticksOn(string s) {
    int count = 0;
    for(char c : s) {
        if(c == '1') {
            count++;
        }
    }
    return count;
}

bool canAchieveNumber(vector<string>& digits, string target, int k) {
    vector<vector<int>> dp(target.size() + 1, vector<int>(k + 1, -1));
    dp[target.size()][0] = 0;

    for(int i = target.size() - 1; i >= 0; i--) {
        for(int j = 0; j <= k; j++) {
            int requiredSticks = countSticksOn(target.substr(i, 7));
            dp[i][j] = -1;
            if(j >= requiredSticks && dp[i+1][j - requiredSticks] != -1) {
                dp[i][j] = i;
            }
        }
    }

    return dp[0][k] != -1;
}


string getMaxNumber(vector<string>& digits, string target, int k) {
    string result = "";
    int sticksLeft = k;

    for(int i = 0; i < target.size(); i++) {
        for(int d = 9; d >= 0; d--) {
            int requiredSticks = countSticksOn(digits[d]);
            if(i + 7 <= target.size() && countSticksOn(target.substr(i, 7)) == requiredSticks && sticksLeft >= requiredSticks) {
                if(i == 0 || (i > 0 && d <= stoi(result.substr(i-1,1)))) {
                    result += to_string(d);
                    sticksLeft -= requiredSticks;
                    break;
                }
            }
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> digits = {
        "1110111", "0010010", "1011101", "1011011", "0111010", 
        "1101011", "1101111", "1010010", "1111111", "1111011"
    };

    vector<string> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if(!canAchieveNumber(digits, nums[n-1], k)) {
        cout << -1 << endl;
    } else {
        string result = getMaxNumber(digits, nums[n-1], k);
        cout << result << endl;
    }

    return 0;
}