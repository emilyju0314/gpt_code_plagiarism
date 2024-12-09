#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<pair<int, int>> variety(n);
        vector<pair<int, int>> fishAndMeat(n);

        for (int j = 0; j < n; j++) {
            int a, b, m;
            cin >> a >> b >> m;
            variety[j] = make_pair(a + b, j);
            fishAndMeat[j] = make_pair(a, b);
        }

        sort(variety.begin(), variety.end());
        int minVariety = variety[0].first;
        
        cout << minVariety << endl;
        for (int j = 0; j < n; j++) {
            int a = fishAndMeat[j].first;
            int b = fishAndMeat[j].second;
            int m = min(a + b, variety[0].first);
            int x = min(m, a);
            int y = m - x;
            cout << x << " " << y << endl;
        }
    }

    return 0;
}