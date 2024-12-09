#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int latitude;
    int longitude;
};

bool isInsidePolygon(Point point, const vector<Point>& polygon) {
    int n = polygon.size();
    bool inside = false;
    for(int i = 0, j = n - 1; i < n; j = i++) {
        if((polygon[i].latitude > point.latitude) != (polygon[j].latitude > point.latitude) &&
           (point.longitude < (polygon[j].longitude - polygon[i].longitude) * (point.latitude - polygon[i].latitude) / (polygon[j].latitude - polygon[i].latitude) + polygon[i].longitude)) {
            inside = !inside;        
        }
    }
    return inside;
}

int main() {
    int N;
    cin >> N;

    Point landingPoint;
    cin >> landingPoint.latitude >> landingPoint.longitude;

    vector<Point> continent(N);
    for(int i = 0; i < N; i++) {
        cin >> continent[i].latitude >> continent[i].longitude;
    }

    if(isInsidePolygon(landingPoint, continent)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}