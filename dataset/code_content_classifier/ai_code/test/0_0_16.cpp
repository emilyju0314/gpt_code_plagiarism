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
        vector<int> order(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
            order[i] = i+1;
        }

        sort(order.begin(), order.end(), [&](int x, int y) {
            return a[x-1] > a[y-1];
        });

        vector<pair<int, int>> ans;
        for(int i=0; i<n-1; i++) {
            ans.push_back({order[i], order[i+1]});
        }

        cout << n-1 << endl;
        for(auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}