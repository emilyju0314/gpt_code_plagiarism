#include <iostream>
#include <vector>

using namespace std;

int main() {
    string num;
    cin >> num;

    int n = num.size();

    vector<int> dp(n+1, n); // Initialize dp array with n

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            string sub_num = num.substr(j - i, i);
            if (sub_num[0] != '0') {
                int sub_num_int = stoi(sub_num);
                if (sub_num_int >= i && dp[j] > dp[j - i] + 1) {
                    dp[j] = dp[j - i] + 1;
                }
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}