#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << "YES" << endl;
        vector<int> ans;
        
        for (int i = 1; i <= n; i++) {
            ans.push_back(2*i - 1);
        }
        
        for (int i = 1; i <= n; i++) {
            ans.push_back(2*i);
        }
        
        for (int i = 0; i < 2*n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}