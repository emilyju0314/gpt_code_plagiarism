#include <iostream>
#include <vector>

using namespace std;

int countGoodSubarrays(string s) {
    int n = s.size();
    vector<int> prefixSum(n+1, 0);
    int count = 0;
    
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + (s[i-1] - '0');
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sum = prefixSum[j] - prefixSum[i-1];
            int len = j - i + 1;
            if (sum == len) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        int result = countGoodSubarrays(s);
        cout << result << endl;
    }
    
    return 0;
}