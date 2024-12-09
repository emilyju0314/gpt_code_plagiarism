#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;

        vector<pair<int, pair<int, int>>> roads; // Vector to store the roads and their traversal times

        for(int i = 0; i < 2*k - 1; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            roads.push_back({t, {a, b}});
        }

        sort(roads.begin(), roads.end());

        long long G = 0, B = 0;

        for(int i = 0; i < k; i++) {
            G += roads[i].first;
        }

        for(int i = 2*k - 2, j = 0; j < k; i--, j++) {
            B += roads[i].first;
        }

        cout << G << " " << B << "\n";
    }

    return 0;
}