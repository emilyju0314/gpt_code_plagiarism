#include <iostream>
#include <vector>

using namespace std;

int countInversions(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    
    vector<int> sorted_a(a.begin(), a.end());
    sort(sorted_a.begin(), sorted_a.end());
    
    int inversions = 0;
    
    for(int i = 0; i < m; i++) {
        int idx = lower_bound(sorted_a.begin(), sorted_a.end(), b[i]) - sorted_a.begin();
        inversions += (n - idx);
    }
    
    return inversions;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        vector<int> b(m);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        cout << countInversions(a, b) << endl;
    }
    
    return 0;
}