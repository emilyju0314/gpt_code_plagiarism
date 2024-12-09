#include <iostream>
#include <vector>

using namespace std;

struct Line {
    int l, r;
};

bool isInsideRectangle(int x, int y, int w, int h) {
    return x >= 0 && x <= w && y >= 0 && y <= h;
}

int calculateArea(int l, int r, int h) {
    return r - l;
}

int main() {
    int n, m, w, h, S;
    
    while (cin >> n >> m >> w >> h >> S) {
        if (n == 0 && m == 0 && w == 0 && h == 0 && S == 0) {
            break;
        }
        
        vector<Line> lines(m);
        for (int i = 0; i < m; i++) {
            cin >> lines[i].l >> lines[i].r;
        }
        
        vector<pair<int, int>> almonds(n);
        for (int i = 0; i < n; i++) {
            cin >> almonds[i].first >> almonds[i].second;
        }
        
        int minAlmonds = n;
        
        // Your implementation to find the minimum number of almonds for Be-ko goes here
        
        cout << minAlmonds << endl;
    }
    
    return 0;
}