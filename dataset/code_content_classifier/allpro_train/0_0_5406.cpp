#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    int lastans = 0;
    
    for (int i = 0; i < q; i++) {
        int type, l, r, k;
        cin >> type;
        
        if (type == 1) {
            cin >> l >> r;
            
            l = ((l + lastans - 1) % n) + 1;
            r = ((r + lastans - 1) % n) + 1;
            
            if (l > r) {
                swap(l, r);
            }
            
            rotate(a.begin() + l - 1, a.begin() + r - 1, a.begin() + r);
        } else {
            cin >> l >> r >> k;
            
            l = ((l + lastans - 1) % n) + 1;
            r = ((r + lastans - 1) % n) + 1;
            k = ((k + lastans - 1) % n) + 1;
            
            if (l > r) {
                swap(l, r);
            }
            
            int count = 0;
            for (int j = l - 1; j < r; j++) {
                if (a[j] == k) {
                    count++;
                }
            }
            
            lastans = count;
            
            cout << count << endl;
        }
    }
    
    return 0;
}