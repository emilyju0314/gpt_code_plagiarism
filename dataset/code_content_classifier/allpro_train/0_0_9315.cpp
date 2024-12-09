#include <iostream>
#include <vector>
#include <cmath>

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
    vector<double> distToBin(n);

    double totalDistance = 0;
    double totalContribution = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        bottles[i] = {x, y};
        distToBin[i] = distance(x, y, tx, ty);
        totalDistance += 2 * distToBin[i];
        totalContribution += distance(x, y, tx, ty);
    }

    double minDistance = totalDistance;
    double minContribution = totalContribution;

    for (int i = 0; i < n; i++) {
        double adilNewContribution = totalContribution - distance(bottles[i].first, bottles[i].second, tx, ty) + distance(bottles[i].first, bottles[i].second, ax, ay);
        double beraNewContribution = totalContribution - distance(bottles[i].first, bottles[i].second, tx, ty) + distance(bottles[i].first, bottles[i].second, bx, by);

        minDistance = min(minDistance, totalDistance - 2 * distToBin[i] + min(adilNewContribution, beraNewContribution));
    }

    cout << fixed;
    cout.precision(6);
    cout << minDistance << endl;

    return 0;
}