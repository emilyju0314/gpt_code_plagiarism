#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    long long prefix_xor = 0;
    long long total_xor = 0;
    
    for(int i=0; i<n; i++) {
        total_xor ^= a[i];
    }
    
    long long max_pleasure = 0;
    
    for(int i=0; i<n; i++) {
        prefix_xor ^= a[i];
        total_xor ^= a[i];
        
        max_pleasure = max(max_pleasure, prefix_xor & total_xor);
    }
    
    cout << max_pleasure << endl;
    
    return 0;
}