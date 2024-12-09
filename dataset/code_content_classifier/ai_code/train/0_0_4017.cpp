#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> arrows;

char getNextDirection(int x, int y, char currentDir) {
    for (auto arrow : arrows) {
        int x0 = arrow.first.first, y0 = arrow.first.second;
        int x1 = arrow.second.first, y1 = arrow.second.second;
        
        if (x == x0 && y == y0) {
            if (currentDir == 'L' && x1 > x0) return 'R';
            if (currentDir == 'R' && x1 < x0) return 'L';
            if (currentDir == 'U' && y1 > y0) return 'D';
            if (currentDir == 'D' && y1 < y0) return 'U';
        }
    }
    return currentDir;
}

int main() {
    int n, b;
    cin >> n >> b;
    
    for (int i = 0; i < n; i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        arrows.push_back({{x0, y0}, {x1, y1}});
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int xi, yi, ti;
        char wi;
        cin >> xi >> yi >> wi >> ti;
        
        while (ti > 0) {
            char nextDir = getNextDirection(xi, yi, wi);
            
            if (wi == 'L') xi--;
            else if (wi == 'R') xi++;
            else if (wi == 'U') yi++;
            else if (wi == 'D') yi--;
            
            ti--;
            wi = nextDir;
            
            if (xi < 0 || xi > b || yi < 0 || yi > b) break;
        }
        
        cout << xi << " " << yi << endl;
    }
    
    return 0;
}