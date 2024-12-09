#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        
        map<int, int> count;
        for(int j=l-1; j<r; j++) {
            count[a[j]]++;
        }

        int ans = 1;
        for(auto it : count) {
            ans = max(ans, (it.second + 1) / 2);
        }

        cout << ans << "\n";
    }

    return 0;
}