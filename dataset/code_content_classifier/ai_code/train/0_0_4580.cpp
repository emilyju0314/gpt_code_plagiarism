#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double findArea(vector<Point>& polygon) {
    int n = polygon.size();
    double area = 0;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
    }
    return abs(area) / 2.0;
}

int main() {
    int M, N;
    while(cin >> M >> N) {
        if(M == 0 && N == 0) {
            break;
        }
        double d;
        cin >> d;
        vector<vector<Point>> islands(M);
        vector<pair<double, vector<Point>>> resourceRegions(N);
        
        for(int i = 0; i < M; i++) {
            int n;
            cin >> n;
            islands[i].resize(n);
            for(int j = 0; j < n; j++) {
                cin >> islands[i][j].x >> islands[i][j].y;
            }
        }
        
        for(int i = 0; i < N; i++) {
            cin >> resourceRegions[i].first;
            int n;
            cin >> n;
            resourceRegions[i].second.resize(n);
            for(int j = 0; j < n; j++) {
                cin >> resourceRegions[i].second[j].x >> resourceRegions[i].second[j].y;
            }
        }
        
        for(int i = 0; i < M; i++) {
            double totalResource = 0;
            for(int j = 0; j < N; j++) {
                double regionArea = findArea(resourceRegions[j].second);
                double distance = 0;
                for(auto point : islands[i]) {
                    for(int k = 0; k < resourceRegions[j].second.size(); k++) {
                        int next = (k + 1) % resourceRegions[j].second.size();
                        int x1 = point.x, y1 = point.y;
                        int x2 = islands[i][j].x, y2 = islands[i][j].y;
                        int x3 = resourceRegions[j].second[k].x, y3 = resourceRegions[j].second[k].y;
                        int x4 = resourceRegions[j].second[next].x, y4 = resourceRegions[j].second[next].y;
                        
                        double dist = abs((y2 - y1) * x3 - (x2 - x1) * y3 + x2 * y1 - y2 * x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
                        if(dist <= d) {
                            distance += dist;
                        }
                    }
                }
                totalResource += distance * resourceRegions[j].first;
            }
            cout << fixed << totalResource << endl;
        }
        cout << endl;
    }
    
    return 0;
}