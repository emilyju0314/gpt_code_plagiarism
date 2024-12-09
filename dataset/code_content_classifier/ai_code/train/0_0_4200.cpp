#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int area = points[i].x * (points[j].y - points[k].y) + points[j].x * (points[k].y - points[i].y) + points[k].x * (points[i].y - points[j].y);
                if (area != 0) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}