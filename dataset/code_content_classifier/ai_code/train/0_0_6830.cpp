#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    vector<string> image(n);
    for (int i = 0; i < n; i++) {
        cin >> image[i];
    }

    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (image[i][j] == '#') {
                total_cost += c; // Painting a single pixel
            } else {
                // Check for horizontal line segment cost
                int length = 1;
                while (j + length < m && image[i][j + length] == '.') {
                    length++;
                }
                if (length > 1) {
                    total_cost += min(a*length + b, c*length); // Choose minimum of painting a line segment or single pixel
                    j += length - 1; // Move to the last pixel of the line segment
                }
            }
        }
    }

    cout << total_cost << endl;

    return 0;
}