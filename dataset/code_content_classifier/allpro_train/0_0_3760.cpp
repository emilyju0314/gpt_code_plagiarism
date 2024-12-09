#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> polyline(n, vector<int>(k+1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            cin >> polyline[i][j];
        }
    }

    cout << fixed << setprecision(12);

    for (int i = 0; i < n; i++) {
        double visible_area = 0.5 * (polyline[i][0] + polyline[i][k]);
        for (int j = 1; j < k; j++) {
            visible_area += 0.5 * (polyline[i][j] + polyline[i][j-1]);
        }
        cout << visible_area << endl;
    }

    return 0;
}