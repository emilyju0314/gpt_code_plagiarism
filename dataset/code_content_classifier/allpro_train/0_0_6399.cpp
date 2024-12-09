#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int caseNum = 1;
    
    while (true) {
        int N;
        cin >> N;
        
        if (N == 0) {
            break;
        }
        
        map<string, int> dict;
        for (int i = 0; i < N; i++) {
            string word;
            int exp;
            cin >> word >> exp;
            dict[word] = exp;
        }
        
        string expression;
        cin >> expression;
        
        vector<int> dp(expression.length() + 1, 0);
        dp[0] = 0;
        
        for (int i = 1; i <= expression.length(); i++) {
            dp[i] = dp[i - 1] + 1;
            string word = "";
            for (int j = i; j >= 1 && j >= i - 198; j--) {
                word = expression[j - 1] + word;
                if (dict.find(word) != dict.end()) {
                    dp[i] = min(dp[i], dp[j - 1] + dict[word]);
                }
            }
        }
        
        cout << "Case " << caseNum << ": " << dp[expression.length()] << endl;
        caseNum++;
    }
    
    return 0;
}