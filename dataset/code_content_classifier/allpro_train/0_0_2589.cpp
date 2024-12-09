#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    int m;
    
    while (true) {
        cin >> m;
        
        if (m == 0) {
            break;
        }
        
        vector<Point> vertices(m);
        for (int i = 0; i < m; i++) {
            cin >> vertices[i].x >> vertices[i].y;
        }
        
        int area = 0;
        for (int i = 0; i < m; i++) {
            area += (vertices[i].x * vertices[(i + 1) % m].y) - (vertices[i].y * vertices[(i + 1) % m].x);
        }
        
        area = abs(area) / 2;
        
        cout << area << endl;
    }
    
    return 0;
}