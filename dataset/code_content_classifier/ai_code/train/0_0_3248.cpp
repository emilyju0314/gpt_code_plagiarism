#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countCorrectSequences(string s) {
    int n = s.length();
    vector<int> balance(n+1, 0);
    for(int i = 0; i < n; i++) {
        balance[i+1] = balance[i] + (s[i] == '(' ? 1 : -1);
    }

    vector<int> dp(n+1, 0);
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(balance[i] >= 0 && balance[i+1] == 0) {
            dp[i+1] = dp[i] + 1;
            result += dp[i+1];
        }
    }

    return result;
}

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    int result = countCorrectSequences(s);
    cout << result << endl;

    return 0;
}