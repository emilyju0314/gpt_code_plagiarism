#include<iostream>
#include<vector>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) {}
};

Point getCenterOfMass(vector<Point>& points) {
    int sumX = 0, sumY = 0;
    for(auto p : points) {
        sumX += p.x;
        sumY += p.y;
    }
    return Point(sumX/3, sumY/3);
}

bool checkCenterOfMass(Point idol, vector<Point>& cities) {
    for(int i = 0; i < cities.size(); i++) {
        for(int j = i+1; j < cities.size(); j++) {
            for(int k = j+1; k < cities.size(); k++) {
                vector<Point> altars = {cities[i], cities[j], cities[k]};
                Point center = getCenterOfMass(altars);
                if(center.x == idol.x && center.y == idol.y) {
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
    
    vector<vector<Point>> cities;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<Point> city;
        for(int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            city.push_back(Point(x, y));
        }
        cities.push_back(city);
    }
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Point hill(x, y);
        
        bool result = false;
        for(auto city : cities) {
            if(checkCenterOfMass(hill, city)) {
                result = true;
                break;
            }
        }
        
        if(result) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}