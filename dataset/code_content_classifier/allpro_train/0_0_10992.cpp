#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> treasures(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        treasures[i] = make_pair(x, y);
    }

    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int count = 0;
        for(auto treasure : treasures) {
            if(treasure.first >= x1 && treasure.first <= x2 && treasure.second >= y1 && treasure.second <= y2) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}