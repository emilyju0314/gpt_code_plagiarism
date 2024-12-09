#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<long long> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n);
    dp[0] = 1;
    
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(abs(h[i]-h[j]) >= d) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int max_length = 0, max_index = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] > max_length) {
            max_length = dp[i];
            max_index = i;
        }
    }

    cout << max_length << endl;
    vector<int> result;
    for(int i = max_index; i >= 0; i--) {
        if(dp[i] == max_length) {
            result.push_back(i+1);
            max_length--;
        }
    }

    for(int i = result.size()-1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    
    return 0;
}