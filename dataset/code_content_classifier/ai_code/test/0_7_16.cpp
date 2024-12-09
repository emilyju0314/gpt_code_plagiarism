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

        vector<int> sociability(n);
        vector<pair<int, int>> res;

        for(int i = 0; i < n; i++) {
            cin >> sociability[i];
        }

        int max_talks = 0;

        for(int i = 0; i < n; i++) {
            if(sociability[i] == 0) continue;
            
            max_talks += sociability[i] / 2;
            res.push_back({i, (i+1) % n});
            sociability[(i+1) % n] -= sociability[i] / 2;
            sociability[i] %= 2;
        }

        cout << max_talks << endl;
        for(auto p : res) {
            cout << p.first+1 << " " << p.second+1 << endl;
        }
    }

    return 0;
}