#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> fortune(6);
    for(int i=0; i<6; i++) {
        cin >> fortune[i];
    }

    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        vector<long long> dp(n+1, INT_MIN);
        dp[0] = 0;

        for(int i=0; i<k; i++) {
            for(int j=n; j>=0; j--) {
                for(int d=9; d>=3; d-=3) {
                    if(j-d >= 0 && dp[j-d] != INT_MIN) {
                        dp[j] = max(dp[j], dp[j-d] + fortune[(int)log10(d)/log10(3)]);
                    }
                }
            }
        }

        cout << dp[n] << endl;
    }

    return 0;
}