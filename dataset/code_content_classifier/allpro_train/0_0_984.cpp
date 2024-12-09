#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    string s;
    cin >> s;
    
    vector<int> digits(10, 0);
    
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        vector<int> dp(2, 1);
        int cp = l - 1;
        
        while(cp >= l - 1 && cp <= r - 1) {
            char curr = s[cp];
            if(isdigit(curr)) {
                int num = curr - '0';
                digits[num]++;
                if(num > 0) s[cp] = num - 1 + '0';
                else {
                    s.erase(cp, 1);
                    r--;
                }
                cp += dp[1];
            }
            else {
                dp[1] = (curr == '>') ? 1 : -1;
                if(cp + dp[1] >= l - 1 && cp + dp[1] <= r - 1 && (s[cp + dp[1]] == '<' || s[cp + dp[1]] == '>')) {
                    s.erase(cp + dp[1], 1);
                    r--;
                }
                cp += dp[1];
            }
        }
        
        for(int j = 0; j < 10; j++) {
            cout << digits[j] << " ";
        }
        cout << endl;
        
        digits = vector<int>(10, 0); // reset for the next query
    }
    
    return 0;
}