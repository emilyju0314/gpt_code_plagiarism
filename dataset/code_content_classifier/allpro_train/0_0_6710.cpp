#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> sequence;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < T; j++) {
            sequence.push_back(a[i]);
        }
    }
    
    vector<int> dp(sequence.size(), 1);
    for(int i = 1; i < sequence.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(sequence[i] >= sequence[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int maxLength = *max_element(dp.begin(), dp.end());
    
    cout << maxLength << endl;
    
    return 0;
}