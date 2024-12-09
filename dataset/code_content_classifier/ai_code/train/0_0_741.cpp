#include <iostream>
#include <vector>

using namespace std;

bool isWinning(vector<int>& s, int n) {
    vector<int> dp(n + 1, -1);
    
    for (int i = 1; i <= n; i++) {
        bool canWin = false;
        for (int x : s) {
            if (i - x < 1) continue;
            if (dp[i - x] == 0) {
                canWin = true;
                break;
            }
        }
        
        dp[i] = canWin ? 1 : 0;
    }
    
    return dp[n] == 1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> s1, s2;
    int k1, k2;
    
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int num;
        cin >> num;
        s1.push_back(num);
    }
    
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int num;
        cin >> num;
        s2.push_back(num);
    }
    
    for (int i = 1; i < n; i++) {
        if (isWinning(s1, i + 1)) {
            cout << "Win ";
        } else {
            cout << "Lose ";
        }
    }
    cout << endl;
    
    for (int i = 1; i < n; i++) {
        if (isWinning(s2, i + 1)) {
            cout << "Win ";
        } else {
            cout << "Lose ";
        }
    }
    cout << endl;
    
    return 0;
}