#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Building {
    int x;
    int h;
};

bool compareBuildings(Building b1, Building b2) {
    return b1.x < b2.x;
}

double calculateTowerHeight(int N, int t, vector<Building>& buildings) {
    double minHeight = 0;

    for (int i = 0; i < N; i++) {
        double height = (double)buildings[i].h / buildings[i].x;
        if (height > minHeight) {
            minHeight = height;
        }
    }

    return minHeight * t;
}

int main() {
    int N, t;
    cin >> N >> t;

    vector<Building> buildings(N);
    for (int i = 0; i < N; i++) {
        cin >> buildings[i].x >> buildings[i].h;
    }

    sort(buildings.begin(), buildings.end(), compareBuildings);

    double towerHeight = calculateTowerHeight(N, t, buildings);

    cout << towerHeight << endl;

    return 0;
}