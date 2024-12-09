#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> pickupLines(n);
    for (int i = 0; i < n; i++) {
        cin >> pickupLines[i];
    }

    vector<long long> dp(l+1, 0);

    for (int i = 1; i <= l; i++) {
        for (int j = 0; j < n; j++) {
            int len = pickupLines[j].length();
            if (i >= len) {
                string substr = pickupLines[j];
                int ptr = len-1;
                int ptr2 = i-1;
                bool match = true;
                
                while(ptr >= 0) {
                    if(ptr2 < 0 || substr[ptr] != dp[ptr2]) {
                        match = false;
                        break;
                    }
                    ptr--;
                    ptr2--;
                }

                if(match) {
                    dp[i] = max(dp[i], dp[i-len] + a[j]);
                }
            }
        }

        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[l] << endl;

    return 0;
}