#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int>& b) {
    int n = b.size();
    vector<int> a(n);
    
    int mx = b[0];
    for (int i = 1; i < n; i++) {
        mx = max(mx, b[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mx - b[i];
    }
    
    if (sum == 0) {
        for (int i = 0; i < n; i++) {
            a[i] = mx;
        }
        return a;
    }
    
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mx - b[i];
        if (sum < 0 || sum % n != 0) {
            return {};
        }
        a[i] = mx - sum / n;
    }
    
    return a;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<int> a = solve(b);
        
        if (a.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}