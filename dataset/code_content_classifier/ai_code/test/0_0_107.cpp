#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int a, int b) {
    if (a == 0 && b == 0) {
        if (n == 2) {
            cout << "1 2\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    
    if (a == 0 || b == 0 || a + b >= n || a + b < n - 1) {
        cout << "-1\n";
        return;
    }
    
    vector<int> ans;
    for (int i = 0; i < b; i++) {
        ans.push_back(i + 2);
    }
    
    ans.push_back(1);
    
    for (int i = b; i < b + a; i++) {
        ans.push_back(n - i + b);
    }
    
    for (int i = b + a + 1; i < n; i++) {
        ans.push_back(i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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