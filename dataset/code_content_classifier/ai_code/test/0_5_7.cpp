#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string a, b;
    cin >> a >> b;
    
    vector<int> ans(n - m + 2, 0);

    for (int k = 0; k <= n - m + 1; k++) {
        int changes = 0;
        for (int i = 0; i < m; i++) {
            if (a[i] != b[i]) {
                changes++;
            }
        }
        ans[k] = changes;
        
        for (int i = 1; i <= n - m; i++) {
            if (a[i - 1] != b[0]) {
                changes--;
            }
            if (i + m - 1 < n && a[i + m - 1] != b[m - 1]) {
                changes++;
            }
            ans[k] = min(ans[k], changes);
        }
        
        if (k + m <= n) {
            a[k + m - 1] = (a[k + m - 1] == '0') ? '1' : '0';
        }
    }

    for (int i = 0; i < n - m + 2; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}