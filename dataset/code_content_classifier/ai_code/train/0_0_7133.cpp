#include <iostream>
#include <vector>

using namespace std;

struct Rectangle {
    int x1, y1, x2, y2, label;
};

bool formSquare(const vector<Rectangle>& rectangles) {
    for (int i = 0; i < rectangles.size(); i++) {
        for (int j = i + 1; j < rectangles.size(); j++) {
            int minX = min(rectangles[i].x1, rectangles[j].x1);
            int minY = min(rectangles[i].y1, rectangles[j].y1);
            int maxX = max(rectangles[i].x2, rectangles[j].x2);
            int maxY = max(rectangles[i].y2, rectangles[j].y2);
            
            // Check if the merged rectangle is a square
            if ((maxX - minX) == (maxY - minY)) {
                // Check if all points of the square are covered by rectangles
                bool allPointsCovered = true;
                for (const Rectangle& rect : rectangles) {
                    if (!(minX >= rect.x1 && minY >= rect.y1 && maxX <= rect.x2 && maxY <= rect.y2)) {
                        allPointsCovered = false;
                        break;
                    }
                }
                
                if (allPointsCovered) {
                    cout << "YES " << rectangles.size() << endl;
                    for (const Rectangle& rect : rectangles) {
                        cout << rect.label << " ";
                    }
                    cout << endl;
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
        rectangles[i].label = i + 1;
    }
    
    if (!formSquare(rectangles)) {
        cout << "NO" << endl;
    }

    return 0;
}