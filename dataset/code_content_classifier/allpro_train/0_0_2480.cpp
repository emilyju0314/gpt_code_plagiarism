#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    vector<Point> points(3);
    
    for (int i = 0; i < 3; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    int k = 3;
    cout << k << endl;
    
    for (int i = 0; i < 3; i++) {
        int x_diff = points[(i+1)%3].x - points[i].x;
        int y_diff = points[(i+1)%3].y - points[i].y;
        
        cout << points[(i+2)%3].x + x_diff << " " << points[(i+2)%3].y + y_diff << endl;
    }
    
    return 0;
}