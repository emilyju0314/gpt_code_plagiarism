#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

double getArea(vector<Point>& landmarks, vector<int>& order) {
    double area = 0;
    for (int i = 0; i < landmarks.size(); i++) {
        Point p1 = landmarks[order[i]];
        Point p2 = landmarks[order[(i + 1) % landmarks.size()]];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    area = abs(area) / 2.0;
    return area;
}

int main() {
    int caseNum = 1;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        
        vector<Point> landmarks(N);
        for (int i = 0; i < N; i++) {
            cin >> landmarks[i].x >> landmarks[i].y;
        }
        
        vector<int> order(N);
        for (int i = 0; i < N; i++) {
            cin >> order[i];
        }
        
        double area = getArea(landmarks, order);
        
        cout << "Case " << caseNum << ": ";
        if (area == 0) {
            cout << "No area" << endl;
        } else if (isinf(area)) {
            cout << "Infinity" << endl;
        } else {
            cout << fixed << setprecision(5) << area << endl;
        }
        
        caseNum++;
    }
    
    return 0;
}