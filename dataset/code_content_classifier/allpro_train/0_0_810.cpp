#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate the area of a square given two points
double calculateSquareArea(int x1, int y1, int x2, int y2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return pow(distance, 2);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }

    double totalArea = 0;
    for (int i = 0; i < n; i++) {
        totalArea += calculateSquareArea(vertices[i].first, vertices[i].second, vertices[(i + 1) % n].first, vertices[(i + 1) % n].second);
    }

    double expectedArea = totalArea / n;
    cout << fixed << expectedArea << endl;

    return 0;
}