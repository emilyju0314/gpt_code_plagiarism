#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    // Input the number of vertices
    int n;
    cin >> n;

    // Input the vertices
    vector<pair<int, int>> vertices;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertices.push_back({x, y});
    }

    // Calculate the perimeter of the polygon
    double perimeter = 0.0;
    for (int i = 0; i < n; i++) {
        perimeter += distance(vertices[i].first, vertices[i].second, vertices[(i+1)%n].first, vertices[(i+1)%n].second);
    }

    // Output the perimeter
    cout << fixed << perimeter << endl;

    return 0;
}