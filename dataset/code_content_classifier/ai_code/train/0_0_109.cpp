#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    
    int n;
    cin >> n;
    
    vector<pair<int, pair<int, int>>> segments;
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        segments.push_back(make_pair(r, make_pair(a, b)));
    }
    
    sort(segments.begin(), segments.end());
    
    int moves = abs(x1 - x0) + abs(y1 - y0);
    for (auto seg : segments) {
        int r = seg.first;
        int a = seg.second.first;
        int b = seg.second.second;

        if ((x0 >= a && x0 <= b) && (x1 >= a && x1 <= b) && r == x0 && r == x1) {
            moves = min(moves, abs(x1 - x0) + abs(y1 - y0));
        } else if (x0 >= a && x0 <= b && r == x0) {
            moves = min(moves, abs(x1 - x0) + abs(y1 - r) + abs(y1 - y0));
        } else if (x1 >= a && x1 <= b && r == x1) {
            moves = min(moves, abs(x1 - r) + abs(x1 - x0) + abs(y1 - y0));
        }
        moves = min(moves, abs(x1 - r) + abs(x1 - x0) + abs(y1 - r) + abs(y1 - y0));
    }
    
    cout << moves << endl;
    
    return 0;
}