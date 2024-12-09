#include <iostream>
#include <vector>

using namespace std;

bool isCircle(vector<vector<int>>& image, int row, int col) {
    // Implement the logic to check if the shape at the given pixel is a circle
    // You can use properties like diameter, number of black pixels around the pixel
}

bool isSquare(vector<vector<int>>& image, int row, int col) {
    // Implement the logic to check if the shape at the given pixel is a square
    // You can use properties like side length, number of black pixels around the pixel
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> image(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    int circles = 0;
    int squares = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (image[i][j] == 1) {
                if (isCircle(image, i, j)) {
                    circles++;
                } else if (isSquare(image, i, j)) {
                    squares++;
                }
            }
        }
    }

    cout << circles << " " << squares << endl;

    return 0;
}