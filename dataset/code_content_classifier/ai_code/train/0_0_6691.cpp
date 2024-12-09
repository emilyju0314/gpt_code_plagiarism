#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int query(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> p(n);
        p[0] = 1;
        
        for (int i = 2; i <= n; ++i) {
            int x = query(1, i, 2);
            if (x == i) {
                p[1] = i;
            } else if (x == i-1) {
                p[1] = 1;
                p[0] = i;
            }
        }
        
        for (int i = 3; i <= n; ++i) {
            int l = 1, r = i-1;
            while (l < r) {
                int m = (l + r) / 2;
                int x = query(1, p[m], i);
                
                if (x == i) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
            
            for (int j = i; j > l; j--) {
                p[j] = p[j-1];
            }
            p[l] = i;
        }
        
        cout << "!";
        for (int i = 0; i < n; ++i) {
            cout << " " << p[i];
        }
        cout << endl;
        cout.flush();
        
        int verdict;
        cin >> verdict;
    }
    
    return 0;
}