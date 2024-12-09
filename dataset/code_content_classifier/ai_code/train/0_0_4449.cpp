#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> predictions(n);
    for (int i = 0; i < n; i++) {
        cin >> predictions[i].first >> predictions[i].second;
    }

    vector<vector<double>> matrix(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double count = 0.0;
            for (int k = 0; k < n; k++) {
                if (predictions[k].first >= predictions[i].first && predictions[k].second <= predictions[i].second) {
                    count += 1.0;
                }
            }
            matrix[i][j] = count / n;
        }
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}