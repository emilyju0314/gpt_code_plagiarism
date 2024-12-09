#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& a, vector<int>& b) {
    long long inversions = 0;
    int n = a.size();
    int m = b.size();
    
    vector<int> c(n + m);
    vector<int> indices(m);
    
    for (int i = 0; i < m; i++) {
        indices[i] = i;
    }
    
    sort(indices.begin(), indices.end(), [&b](int x, int y) {
        return b[x] < b[y];
    });
    
    for (int i = 0, j = 0, k = 0; i < n + m; i++) {
        if (j < n && (k == m || a[j] <= b[indices[k]])) {
            c[i] = a[j++];
        } else {
            c[i] = b[indices[k++]];
            inversions += n - j;
        }
    }
    
    return inversions;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        vector<int> b(m);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        cout << merge(a, b) << endl;
    }
    
    return 0;
}