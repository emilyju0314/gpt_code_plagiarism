#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        vector<pair<int,int>> points(4);
        for(int i=0; i<4; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
        }
        
        sort(points.begin(), points.end());
        
        int xc = (points[0].first + points[3].first) / 2;
        int yc = (points[0].second + points[3].second) / 2;
        
        int d1 = max(abs(points[0].first - points[3].first), abs(points[0].second - points[3].second));
        int d2 = max(abs(points[1].first - points[2].first), abs(points[1].second - points[2].second));
        int d = max(d1, d2);
        
        if((points[1].first + points[2].first) == 2*xc && (points[1].second + points[2].second) == 2*yc) {
            cout << d*d << endl;
            cout << points[0].first + xc - points[1].first << " " << points[0].second + yc - points[1].second << endl;
            cout << points[0].first + xc - points[2].first << " " << points[0].second + yc - points[2].second << endl;
            cout << points[0].first + xc - points[3].first << " " << points[0].second + yc - points[3].second << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}