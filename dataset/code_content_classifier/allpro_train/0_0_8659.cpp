#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool plane[2001][2001] = {false}; // Initialize the plane as uncovered

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                plane[x][y] = true;
            }
        }
    }

    int area = 0;
    for (int x = 0; x < 2001; x++) {
        for (int y = 0; y < 2001; y++) {
            if (plane[x][y]) {
                area++;
            }
        }
    }

    cout << area << endl;

    return 0;
}