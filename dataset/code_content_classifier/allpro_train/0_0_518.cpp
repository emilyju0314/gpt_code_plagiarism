#include <iostream>
#include <vector>
#include <string>

#define mod 1000000007

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> prefixCount(n, 0);
    vector<int> dp(n, 0);

    for(int i = 1; i < n; i++) {
        prefixCount[i] = prefixCount[i-1] + (s[i-1] == 'a');
    }

    dp[0] = (s[0] == 'a' ? 1 : 0);

    for(int i = 1; i < n; i++) {
        dp[i] = dp[i-1];
        if(s[i] == 'a') {
            dp[i] += prefixCount[i];
        }
        dp[i] %= mod;
    }

    int answer = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            answer = (answer + dp[i]) % mod;
        }
    }

    cout << answer << endl;

    return 0;
}