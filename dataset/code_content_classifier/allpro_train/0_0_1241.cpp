#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<int> min_occurrence(n + 1, n);
        vector<int> max_occurrence(n + 1, -1);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            min_occurrence[a[i]] = min(min_occurrence[a[i]], i);
            max_occurrence[a[i]] = max(max_occurrence[a[i]], i);
        }
        
        vector<int> ans(n + 1, -1);
        
        for(int k = 1; k <= n; k++) {
            for(int i = 0; i < n - k + 1; i++) {
                int minimum = n;
                for(int j = i; j < i + k; j++) {
                    minimum = min(minimum, max_occurrence[a[j]]);
                }
                if(minimum <= i) {
                    ans[k] = a[i];
                    break;
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}