#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    int n;
    cin >> n;

    vector<pair<int, int>> bottles(n);
    for (int i = 0; i < n; i++) {
        cin >> bottles[i].first >> bottles[i].second;
    }

    vector<double> adilDistances(n), beraDistances(n), totalDistances(n);
    double totalAdil = 0, totalBera = 0, totalDist;

    for (int i = 0; i < n; i++) {
        adilDistances[i] = distance(ax, ay, bottles[i].first, bottles[i].second);
        beraDistances[i] = distance(bx, by, bottles[i].first, bottles[i].second);
        totalDistances[i] = distance(tx, ty, bottles[i].first, bottles[i].second);
        totalAdil += 2 * totalDistances[i] + adilDistances[i] - totalDistances[i];
        totalBera += 2 * totalDistances[i] + beraDistances[i] - totalDistances[i];
    }

    double minTotal = min(totalAdil, totalBera);

    for (int i = 0; i < n; i++) {
        double newAdil = totalAdil + beraDistances[i] - totalDistances[i];
        double newBera = totalBera + adilDistances[i] - totalDistances[i];
        double newTotal = min(newAdil, newBera);
        minTotal = min(minTotal, newTotal);
    }

    cout << fixed << minTotal << endl;

    return 0;
}