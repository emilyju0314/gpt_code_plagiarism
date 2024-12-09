#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateCoverageArea(vector<vector<double>>& antennas) {
    int n = antennas.size();
    double totalArea = 0.0;

    for (int i = 0; i < n; i++) {
        double minX = antennas[i][0] - antennas[i][2];
        double maxX = antennas[i][0] + antennas[i][2];
        double minY = antennas[i][1] - antennas[i][2];
        double maxY = antennas[i][1] + antennas[i][2];

        for (int j = i + 1; j < n; j++) {
            double currX = antennas[j][0];
            double currY = antennas[j][1];

            minX = max(minX, currX - antennas[j][2]);
            maxX = min(maxX, currX + antennas[j][2]);
            minY = max(minY, currY - antennas[j][2]);
            maxY = min(maxY, currY + antennas[j][2]);
        }

        totalArea += abs(maxX - minX) * abs(maxY - minY);
    }

    return totalArea;
}

int main() {
    int dataset = 1;
    int n;

    while (true) {
        cin >> n;
        
        if (n == 0) {
            break;
        }

        vector<vector<double>> antennas(n, vector<double>(3));

        for (int i = 0; i < n; i++) {
            cin >> antennas[i][0] >> antennas[i][1] >> antennas[i][2];
        }

        double totalArea = calculateCoverageArea(antennas);

        cout << dataset << " " << fixed << setprecision(2) << totalArea << endl;
        
        dataset++;
    }

    return 0;
}