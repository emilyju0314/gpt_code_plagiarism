#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> count;
        
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans += count[i - a[i]];
            count[i + a[i]]++;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}