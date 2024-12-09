#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double dist(pair<int, int> p1, pair<int, int> p2){
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for(int i=0; i<N; i++){
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;
    // Distance from first point to last point
    total_distance += dist(points[0], points[N-1]);
    
    // Distance from the turn-around point to the leftmost point
    double min_distance = dist(points[0], points[N-1]);
    for(int i=0; i<N-1; i++){
        double distance = dist(points[i], points[N-1]) + dist(points[i], points[0]);
        min_distance = min(min_distance, distance);
    }
    total_distance += min_distance;

    // Distance from the turn-around point to the starting point
    total_distance += dist(points[0], points[N-1]);

    cout.precision(8);
    cout << total_distance << endl;
    
    return 0;
}