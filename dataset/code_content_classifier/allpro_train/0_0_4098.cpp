#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    cin >> m;
    vector<int> widths(m);
    for (int i = 0; i < m; i++) {
        cin >> widths[i];
    }
    
    vector<double> expected_heights;
    for (int i = 0; i < m; i++) {
        double sum = 0;
        for (int j = 0; j <= n - widths[i]; j++) {
            int min_height = heights[j];
            for (int k = 1; k < widths[i]; k++) {
                min_height = min(min_height, heights[j + k]);
            }
            sum += min_height;
        }
        double expected_height = sum / (n - widths[i] + 1);
        expected_heights.push_back(expected_height);
    }
    
    cout << fixed << setprecision(9);
    for (int i = 0; i < m; i++) {
        cout << expected_heights[i] << " ";
    }
    
    return 0;
}