#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    long long max_val = LLONG_MIN;
    long long max_p = LLONG_MIN, max_r = LLONG_MIN;
    
    for(int i = 0; i < n; i++) {
        max_p = max(max_p, (long long)p * nums[i]);
        max_val = max(max_val, max_p + max_r);
        
        max_r = max(max_r, (long long)r * nums[i]);
        max_val = max(max_val, max_p + max_r);
    }
    
    cout << max_val << endl;
    
    return 0;
}