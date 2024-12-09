#include <iostream>
#include <vector>

using namespace std;

int countOnes(int n, int l, int r) {
    if(n == 0 || l > r) {
        return 0;
    }
    
    vector<int> counts(2, 0);
    counts[1] = n;
    
    int totalOnes = 0;
    int prev = 1;
    
    for(int i = 1; i <= r; i++) {
        int ones = counts[1];
        int zeros = counts[0];
        
        if(i >= l) {
            totalOnes += ones;
        }
        
        if(prev == 1) {
            counts[0] += ones;
            counts[1] = 0;
            prev = 0;
        } else {
            counts[1] = zeros;
            prev = 1;
        }
    }
    
    return totalOnes;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    
    cout << countOnes(n, l, r) << endl;
    
    return 0;
}