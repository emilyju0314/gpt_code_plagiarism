#include <iostream>
#include <vector>

using namespace std;

void buildTree(vector<int>& a, int left, int right, int depth, vector<int>& d) {
    if(left > right) return;
    
    int index = left;
    for(int i = left+1; i <= right; i++) {
        if(a[i] > a[index]) {
            index = i;
        }
    }
    
    d[a[index]-1] = depth;
    
    buildTree(a, left, index-1, depth+1, d);
    buildTree(a, index+1, right, depth+1, d);
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<int> d(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        buildTree(a, 0, n-1, 0, d);
        
        for(int i = 0; i < n; i++) {
            cout << d[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}