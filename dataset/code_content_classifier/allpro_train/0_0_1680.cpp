#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int minC = INT_MAX;
    for(int i = 0; i <= k; i++) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        int c = 0;
        for(int j = 0; j < i; j++) {
            c = max(c, b[j]);
        }
        minC = min(minC, c);
    }
    
    cout << minC << endl;
    
    return 0;
}