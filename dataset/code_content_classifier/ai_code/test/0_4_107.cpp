#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int a, int b) {
    if (a == 0 && b == 0) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
    } else if (a + b > n - 1 || a * 2 < b + 1 || b * 2 < a + 1) {
        cout << -1 << endl;
    } else {
        vector<int> permutation;
        for (int i = 1; i <= a + 1; i++) {
            permutation.push_back(i * 2);
        }
        for (int i = 0; i < b; i++) {
            permutation.insert(permutation.begin() + i, i * 2 + 1);
        }
        for (int i = a + b + 1; i <= n; i++) {
            permutation.push_back(i - (a + b - 1));
        }
        
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        solve(n, a, b);
    }
    
    return 0;
}