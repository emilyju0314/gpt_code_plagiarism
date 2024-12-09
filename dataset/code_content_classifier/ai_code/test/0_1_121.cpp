#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min_operations(string a, string b) {
    int n = a.length();
    
    // Check if a and b are already the same
    if(a == b) {
        return 0;
    }
    
    vector<int> diff(n);
    
    // Calculate differences between corresponding characters of a and b
    for(int i = 0; i < n; i++) {
        diff[i] = a[i] != b[i];
    }
    
    // Check if sum of differences is odd
    if(accumulate(diff.begin(), diff.end(), 0) % 2 != 0) {
        return -1;
    }
    
    // Count number of operations required
    int ops = 0;
    for(int i = 0; i < n-1; i++) {
        if(diff[i] == 1) {
            diff[i] = 0;
            diff[i+1] = 1 - diff[i+1];
            ops++;
        }
    }
    
    return ops;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        string a, b;
        
        cin >> n >> a >> b;
        
        int ans = min_operations(a, b);
        cout << ans << endl;
    }
    
    return 0;
}