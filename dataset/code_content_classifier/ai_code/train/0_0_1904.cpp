#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_inside_polygon(int x, int y, vector<pair<int, int>>& vertices) {
    int n = vertices.size();
    bool inside = true;
    for (int i = 0; i < n; i++) {
        int x1 = vertices[i].first, y1 = vertices[i].second;
        int x2 = vertices[(i + 1) % n].first, y2 = vertices[(i + 1) % n].second;
        int cross_product = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
        if (cross_product > 0) {
            inside = false;
            break;
        }
    }
    return inside;
}

double find_min_radius(vector<pair<int, int>>& vertices, vector<pair<int, int>>& circles) {
    double low = 0, high = 1e9;
    double min_radius = 0;
    
    while (high - low > 1e-6) {
        double mid = (low + high) / 2;
        bool valid = true;
        
        for (auto& vertex : vertices) {
            double closest_dist = 1e9;
            for (auto& circle : circles) {
                double dist = sqrt(pow(vertex.first - circle.first, 2) + pow(vertex.second - circle.second, 2));
                if (dist - mid <= 1e-6) {
                    closest_dist = min(closest_dist, dist);
                }
            }
            
            if (closest_dist + mid < 1e9) {
                continue;
            } else {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            high = mid;
            min_radius = mid;
        } else {
            low = mid;
        }
    }
    
    return min_radius;
}

int main() {
    int N, M;
    cin >> N;
    vector<pair<int, int>> vertices(N);
    for (int i = 0; i < N; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }
    
    cin >> M;
    vector<pair<int, int>> circles(M);
    for (int i = 0; i < M; i++) {
        cin >> circles[i].first >> circles[i].second;
    }
    
    double min_radius = find_min_radius(vertices, circles);
    cout << min_radius << endl;
    
    return 0;
}