#include <iostream>
#include <string>

using namespace std;

string shortestRegularBracketSequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    
    int dp[n + 1][m + 1];
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    
    for(int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
    }
    
    string result = "";
    
    int i = n, j = m;
    
    while(i > 0 && j > 0) {
        if(s[i - 1] == t[j - 1]) {
            result = s[i - 1] + result;
            i--;
            j--;
        } else if(dp[i - 1][j] < dp[i][j - 1]) {
            result = s[i - 1] + result;
            i--;
        } else {
            result = t[j - 1] + result;
            j--;
        }
    }
    
    while(i > 0) {
        result = s[i - 1] + result;
        i--;
    }
    
    while(j > 0) {
        result = t[j - 1] + result;
        j--;
    }
    
    return result;
}

int main() {
    string s, t;
    cin >> s >> t;
    
    string result = shortestRegularBracketSequence(s, t);
    
    cout << result << endl;
    
    return 0;
}