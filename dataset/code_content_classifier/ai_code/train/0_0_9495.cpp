#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_f = 0;
    
    for(int l = 0; l < n; l++) {
        for(int r = l+1; r < n; r++) {
            int f = abs(a[l] - a[r]) + (r - l);
            max_f = max(max_f, f);
        }
    }
    
    cout << max_f << endl;
    
    return 0;
}