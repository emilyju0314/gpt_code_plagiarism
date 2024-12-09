#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

bool isPentagram(vector<Point>& points) {
    int countIntersections = 0;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=j+1; k<5; k++) {
                int det = (points[j].x - points[i].x) * (points[k].y - points[i].y) - (points[j].y - points[i].y) * (points[k].x - points[i].x);
                if(det == 0) return false; // 3 points are collinear
                countIntersections++;
            }
        }
    }
    return countIntersections == 5;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for(int i=0; i<n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    int countPentagrams = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                for(int l=k+1; l<n; l++) {
                    for(int m=l+1; m<n; m++) {
                        vector<Point> pentagram = {points[i], points[j], points[k], points[l], points[m]};
                        if(isPentagram(pentagram)) {
                            countPentagrams++;
                        }
                    }
                }
            }
        }
    }
    
    cout << countPentagrams << endl;
    
    return 0;
}