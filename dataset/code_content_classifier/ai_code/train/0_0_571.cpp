#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> cakes(n);
    for (int i = 0; i < n; i++) {
        cin >> cakes[i];
    }
    
    for (int i = 0; i < m; i++) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        
        if (op == 1) {
            for (int j = l - 1; j < r; j++) {
                if (cakes[j] > x) {
                    cakes[j] -= x;
                }
            }
        } else if (op == 2) {
            int count = 0;
            for (int j = l - 1; j < r; j++) {
                if (cakes[j] == x) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }
    
    return 0;
}