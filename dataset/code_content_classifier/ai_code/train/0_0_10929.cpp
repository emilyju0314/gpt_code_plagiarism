#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int pos = -1;
            for(int j = i; j < n - 2; j++) {
                if(a[j] > a[j + 2]) {
                    pos = j;
                    break;
                }
            }
            if(pos == -1) {
                break;
            }
            for(int j = pos; j < n - 2; j++) {
                swap(a[j], a[j + 1]);
                ans.push_back(j + 1);
            }
        }
        
        if(ans.size() > n * n) {
            cout << -1 << endl;
        } else {
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}