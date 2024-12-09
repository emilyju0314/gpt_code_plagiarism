#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cities[i] = make_pair(x, y);
    }
    
    vector<int> sons(9);
    for (int i = 0; i < 9; i++) {
        cin >> sons[i];
    }
    
    sort(cities.begin(), cities.end());
    
    bool found = false;
    for (int a = 1; a < n - 2; a++) {
        for (int b = a + 1; b < n - 1; b++) {
            for (int c = b + 1; c < n; c++) {
                if (sons[0] == a && sons[1] == b - a && sons[2] == c - b &&
                    sons[3] == n - c && sons[0] + sons[3] == sons[1] + sons[2]) {
                    cout << cities[a-1].first + 0.5 << " " << cities[a].first + 0.5 << endl;
                    cout << cities[b-1].second + 0.5 << " " << cities[b].second + 0.5 << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) break;
    }
    
    if (!found) {
        cout << -1 << endl;
    }
    
    return 0;
}