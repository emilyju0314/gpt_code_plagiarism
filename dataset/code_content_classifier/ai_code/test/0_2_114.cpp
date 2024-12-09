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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<pair<int, int>> pairs;

        for(int i = 0; i < n/2; i++) {
            pairs.push_back({a[i], a[n-1-i]});
        }

        for(auto p : pairs) {
            cout << p.second << " " << p.first << endl;
        }
    }

    return 0;
}