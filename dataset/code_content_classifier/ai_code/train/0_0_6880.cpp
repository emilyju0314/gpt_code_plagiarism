#include <iostream>
#include <vector>

using namespace std;

int GukiZiana(vector<int>& a, int y) {
    int n = a.size();
    int max_diff = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == y) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] == y) {
                    max_diff = max(max_diff, j - i);
                }
            }
        }
    }
    return max_diff;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = l - 1; j < r; j++) {
                a[j] += x;
            }
        } else if (type == 2) {
            int y;
            cin >> y;
            cout << GukiZiana(a, y) << endl;
        }
    }
    
    return 0;
}