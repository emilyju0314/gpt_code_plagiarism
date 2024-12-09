#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// Function to calculate the area of a polygon formed by the given points
double calculateArea(const vector<Point>& points) {
    int n = points.size();
    double area = 0.0;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y) - (points[j].x * points[i].y);
    }
    return abs(area) / 2.0;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<Point> stages(N);
    for(int i = 0; i < N; i++) {
        cin >> stages[i].x >> stages[i].y;
    }
    
    double maxArea = 0.0;
    
    // Generate all combinations of K stages
    vector<int> indices(N);
    for(int i = 0; i < K; i++) {
        indices[i] = 1;
    }
    
    do {
        vector<Point> selectedStages;
        for(int i = 0; i < N; i++) {
            if(indices[i] == 1) {
                selectedStages.push_back(stages[i]);
            }
        }
        
        // Check if the selected stages form a convex polygon
        bool isConvex = true;
        for(int i = 0; i < K; i++) {
            Point p1 = selectedStages[i];
            Point p2 = selectedStages[(i + 1) % K];
            Point p3 = selectedStages[(i + 2) % K];
            
            if((p3.y - p1.y) * (p2.x - p1.x) > (p2.y - p1.y) * (p3.x - p1.x)) {
                isConvex = false;
                break;
            }
        }
        
        // Calculate the area if the selected stages form a convex polygon
        if(isConvex) {
            double area = calculateArea(selectedStages);
            maxArea = max(maxArea, area);
        }
    } while(next_permutation(indices.begin(), indices.end()));
    
    printf("%.2f\n", maxArea);
    
    return 0;
}