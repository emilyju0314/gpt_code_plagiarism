#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> numbers;
int target;

void shred(string num) {
    numbers.clear();
    for (char c : num) {
        numbers.push_back(c - '0');
    }
    int n = num.size();
    
    int dp[n + 1][target + 1];
    memset(dp, -1, sizeof(dp));
    
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (dp[i-1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if (j + numbers[i-1] <= target) {
                    dp[i][j+numbers[i-1]] = max(dp[i][j+numbers[i-1]], dp[i-1][j] * 10 + numbers[i-1]);
                }
            }
        }
    }
    
    if (dp[n][target] == -1) {
        cout << "error" << endl;
        return;
    }
    
    vector<int> parts;
    int sum = dp[n][target];
    for (int i = n; i > 0; i--) {
        parts.push_back(sum % 10);
        sum /= 10;
    }
    reverse(parts.begin(), parts.end());
    
    cout << dp[n][target] << " ";
    for (int part : parts) {
        cout << part << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
        cin >> target;
        if (target == 0) break;
        
        string num;
        cin >> num;
        
        shred(num);
    }
    
    return 0;
}