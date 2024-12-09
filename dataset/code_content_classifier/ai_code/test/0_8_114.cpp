#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        set<int> s;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        vector<pair<int, int>> pairs;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int x = a[i], y = a[j];
                if(x % y != 0 && y % x != 0 && !s.count(x % y) && !s.count(y % x)) {
                    pairs.push_back({x, y});
                }
            }
        }

        for(int i = 0; i < n/2; i++) {
            cout << pairs[i].first << " " << pairs[i].second << endl;
        }
    }

    return 0;
}