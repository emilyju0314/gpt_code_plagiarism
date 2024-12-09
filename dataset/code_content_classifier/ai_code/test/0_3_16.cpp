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

        vector<pair<int, int>> sociability(n);
        for(int i = 0; i < n; i++) {
            cin >> sociability[i].first;
            sociability[i].second = i + 1;
        }

        sort(sociability.begin(), sociability.end(), greater<pair<int, int>>());

        int k = min(n-1, count_if(sociability.begin(), sociability.end(), [](pair<int, int> p){ return p.first != 0; }));

        cout << k << endl;
        for(int i = 1; i <= k; i++) {
            cout << sociability[0].second << " " << sociability[i].second << endl;
        }
    }

    return 0;
}