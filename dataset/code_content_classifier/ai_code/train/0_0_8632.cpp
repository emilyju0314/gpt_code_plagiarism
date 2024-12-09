#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

int main() {
    int n;
    cin >> n;
    
    vector<Rectangle> rectangles(n);
    set<int> uniqueColors;
    
    for(int i=0; i<n; i++) {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
        uniqueColors.insert(i+1);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(rectangles[i].x1 < rectangles[j].x2 &&
               rectangles[i].x2 > rectangles[j].x1 &&
               rectangles[i].y1 < rectangles[j].y2 &&
               rectangles[i].y2 > rectangles[j].y1) {
                uniqueColors.erase(j+1);
            }
        }
    }
    
    cout << uniqueColors.size() << endl;
    
    return 0;
}