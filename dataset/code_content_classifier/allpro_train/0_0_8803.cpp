#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            
            set<int> counts;
            for(int j = l-1; j < r; j++) {
                counts.insert(a[j]);
            }
            
            int mex = 0;
            for(auto it = counts.begin(); mex == *it; mex++, it++);
            
            cout << mex << endl;
        } else {
            int p, x;
            cin >> p >> x;
            
            a[p-1] = x;
        }
    }
    
    return 0;
}