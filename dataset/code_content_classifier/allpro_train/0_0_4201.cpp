#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long result = 0;
    vector<long long> prefix(n), suffix(n);
    
    prefix[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] | a[i];
    }
    
    suffix[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] | a[i];
    }
    
    for(int i = 0; i < n; i++) {
        long long current = a[i];
        for(int j = 1; j <= k; j++) {
            current *= x;
        }
        
        long long temp = current;
        
        if(i > 0) {
            temp |= prefix[i-1];
        }
        if(i < n-1) {
            temp |= suffix[i+1];
        }
        
        result = max(result, temp);
    }
    
    cout << result << endl;
    
    return 0;
}