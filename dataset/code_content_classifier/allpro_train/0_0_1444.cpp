#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> requiredHeights(n);
    for(int i = 0; i < n; i++) {
        cin >> requiredHeights[i];
    }
    
    long long d = 0;
    long long totalCutLength = 0;
    
    while(totalCutLength <= k) {
        long long maxDays = 0;
        
        for(int i = 0; i < n; i++) {
            if(requiredHeights[i] - d > 0) {
                maxDays = max(maxDays, (requiredHeights[i] - d + i) / (i+1));
            }
        }
        
        long long cutLength = 0;
        
        for(int i = 0; i < n; i++) {
            cutLength += max(0LL, ((maxDays * (i+1)) - requiredHeights[i]));
        }
        
        if(cutLength > k) {
            break;
        }
        
        d = maxDays;
        totalCutLength = cutLength;
    }
    
    cout << d << endl;
    
    return 0;
}