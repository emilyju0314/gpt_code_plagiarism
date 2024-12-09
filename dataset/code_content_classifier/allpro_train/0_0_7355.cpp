#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double findLargestSquare(vector<pair<int, int>>& circles) {
    double max_side_length = 0.0;
    
    for (int i = 0; i < circles.size() - 1; i++) {
        double dist_between_centers = circles[i + 1].first - circles[i].first;
        double combined_radius = circles[i].second + circles[i + 1].second;
        
        double side_length = min(dist_between_centers - combined_radius, combined_radius);
        max_side_length = max(max_side_length, side_length);
    }
    
    return max_side_length;
}

int main() {
    int N;
    
    while (true) {
        cin >> N;
        
        if (N == 0) {
            break;
        }
        
        vector<pair<int, int>> circles(N);
        for (int i = 0; i < N; i++) {
            cin >> circles[i].first >> circles[i].second;
        }
        
        double largest_square_side = findLargestSquare(circles);
        
        cout << fixed;
        cout.precision(10);
        cout << largest_square_side * 2 << endl;
    }
    
    return 0;
}