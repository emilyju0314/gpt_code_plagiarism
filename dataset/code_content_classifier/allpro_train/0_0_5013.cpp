#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double dotProduct(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double angleBetweenVectors(Point a, Point b) {
    return atan2(crossProduct(a, b), dotProduct(a, b));
}

int main() {
    int M, N;
    
    while (cin >> M >> N && M != 0 && N != 0) {
        vector<Point> equipment(M);
        vector<Point> patient(N);
        
        for (int i = 0; i < M; i++) {
            cin >> equipment[i].x >> equipment[i].y;
        }
        
        for (int i = 0; i < N; i++) {
            cin >> patient[i].x >> patient[i].y;
        }
        
        Point center;
        cin >> center.x >> center.y;
        
        double maxAngle = 360.0;
        
        for (int i = 0; i < M; i++) {
            Point a = {equipment[i].x - center.x, equipment[i].y - center.y};
            Point b = {equipment[(i + 1) % M].x - center.x, equipment[(i + 1) % M].y - center.y};
            
            double minAngle = 360.0;
            
            for (int j = 0; j < N; j++) {
                Point c = {patient[j].x - center.x, patient[j].y - center.y};
                Point d = {patient[(j + 1) % N].x - center.x, patient[(j + 1) % N].y - center.y};
                
                double angle1 = angleBetweenVectors(c, a);
                double angle2 = angleBetweenVectors(d, a);
                double angle3 = angleBetweenVectors(c, b);
                double angle4 = angleBetweenVectors(d, b);
                
                if (angle1 * angle2 < 0.0 || angle3 * angle4 < 0.0) {
                    minAngle = 0.0;
                    break;
                }
                
                minAngle = min(minAngle, min(abs(angle1), abs(angle2)));
                minAngle = min(minAngle, min(abs(angle3), abs(angle4)));
            }
            
            maxAngle = min(maxAngle, minAngle);
        }
        
        if (maxAngle == 360.0) {
            cout << "360.0000000" << endl;
        } else {
            cout << fixed << maxAngle * 180.0 / M_PI << endl;
        }
    }
    
    return 0;
}