#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    
    vector<pair<pair<int, int>, pair<int, int>>> arrows;
    for (int i = 0; i < n; i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        arrows.push_back(make_pair(make_pair(min(x0, x1), min(y0, y1)), make_pair(max(x0, x1), max(y0, y1))));
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int xi, yi, ti;
        char wi;
        
        cin >> xi >> yi >> wi >> ti;
        
        while (ti > 0) {
            int minT = b + 1;
            for (auto arrow : arrows) {
                int x0 = arrow.first.first;
                int y0 = arrow.first.second;
                int x1 = arrow.second.first;
                int y1 = arrow.second.second;
                
                if ((wi == 'U' && (yi < y1 || (yi == y1 && xi >= x0 && xi <= x1))) || (wi == 'D' && (yi > y0 || (yi == y0 && xi >= x0 && xi <= x1)))) {
                    int timeToArrow = abs(yi - (wi == 'U' ? y1 : y0));
                    minT = min(minT, timeToArrow);
                }
                
                if ((wi == 'R' && (xi < x1 || (xi == x1 && yi >= y0 && yi <= y1))) || (wi == 'L' && (xi > x0 || (xi == x0 && yi >= y0 && yi <= y1))) ) {
                    int timeToArrow = abs(xi - (wi == 'R' ? x1 : x0));
                    minT = min(minT, timeToArrow);
                }
            }
            
            minT = min(minT, ti);
            
            ti -= minT;
            
            if (wi == 'U') yi += minT;
            else if (wi == 'D') yi -= minT;
            else if (wi == 'R') xi += minT;
            else xi -= minT;
        }
        
        cout << xi << " " << yi << endl;
    }
    
    return 0;
}