#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> flowers(m);
        for(int i = 0; i < m; i++) {
            cin >> flowers[i].first >> flowers[i].second;
        }

        sort(flowers.begin(), flowers.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if(a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        });

        long long happiness = 0;
        int remaining = n;
        for(auto& flower : flowers) {
            if(remaining >= 1) {
                happiness += flower.first;
                remaining--;
            } else {
                happiness += max(0, flower.second);
            }
        }

        cout << happiness << endl;
    }

    return 0;
}