#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double maxDistance(vector<Point>& corridors, Point it) {
    double maxDist = 0;

    for(int i = 0; i < corridors.size(); i++) {
        double dist1 = distance(corridors[i], it);
        double dist2 = distance(corridors[i + 1], it);
        double dist = distance(corridors[i], corridors[i + 1]);

        double finalDist = dist1 > dist2 ? dist1 : dist2;

        if(finalDist > maxDist) {
            maxDist = finalDist;
        }
    }

    return maxDist;
}

int main() {
    int N;
    
    while(cin >> N && N != 0) {
        vector<Point> corridors(N);
        
        for(int i = 0; i < N; i++) {
            cin >> corridors[i].x >> corridors[i].y >> corridors[i + 1].x >> corridors[i + 1].y;
        }
        
        Point it;
        cin >> it.x >> it.y;
        
        double result = maxDistance(corridors, it);
        cout << fixed << result << endl;
    }

    return 0;
}