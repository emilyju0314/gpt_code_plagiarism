#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pies(n);
    for(int i = 0; i < n; i++) {
        cin >> pies[i];
    }
    
    sort(pies.begin(), pies.end());
    
    long long totalCost = 0;
    
    // Pay full price for every other pie starting from the last one
    for(int i = n-1; i >= 0; i -= 2) {
        totalCost += pies[i];
    }
    
    cout << totalCost << endl;
    
    return 0;
}