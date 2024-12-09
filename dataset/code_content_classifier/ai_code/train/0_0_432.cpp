#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        // Calculate the total number of cells on the chessboard
        long long total_cells = static_cast<long long>(n) * static_cast<long long>(m);

        // Calculate the area of the white rectangle
        long long white_area = static_cast<long long>((x2 - x1 + 1)) * static_cast<long long>((y2 - y1 + 1);

        // Calculate the area of the black rectangle
        long long black_area = static_cast<long long>((x4 - x3 + 1)) * static_cast<long long>((y4 - y3 + 1);

        // Calculate the overlapping area between white and black rectangles
        int x_overlap = max(0, min(x2, x4) - max(x1, x3) + 1);
        int y_overlap = max(0, min(y2, y4) - max(y1, y3) + 1);
        long long overlap_area = static_cast<long long>(x_overlap) * static_cast<long long>(y_overlap);

        // Calculate the final number of white and black cells after painting
        long long white_cells = white_area - overlap_area;
        long long black_cells = black_area - overlap_area;

        cout << white_cells << " " << black_cells << endl;
    }

    return 0;
}