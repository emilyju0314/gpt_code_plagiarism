#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> y(n);
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }
    
    unordered_set<int> seen;
    vector<int> x;
    
    sort(y.begin(), y.end());
    
    for(int i = 0; i < n; i++) {
        int cur = y[i];
        x.push_back(cur);
        seen.insert(cur);
        while(seen.count(cur*2) || seen.count(cur*2 + 1)) {
            if(!seen.count(cur*2)) {
                cur *= 2;
            } else {
                cur = cur*2 + 1;
            }
            x.push_back(cur);
            seen.insert(cur);
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    
    return 0;
}