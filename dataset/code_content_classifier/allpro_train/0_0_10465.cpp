#include <iostream>
#include <vector>

using namespace std;

int X, Y;
vector<vector<int>> course;

int countSlides(int x, int y) {
    if (x < 0 || x >= X || y >= Y || course[y][x] == 1) {
        return 0;
    }

    if (y == Y-1) {
        return 1;
    }

    int count = 0;
    if (course[y][x] == 2) {
        count += countSlides(x, y+2);
    }

    count += countSlides(x-1, y+1);
    count += countSlides(x, y+1);
    count += countSlides(x+1, y+1);

    return count;
}

int main() {
    while (true) {
        cin >> X >> Y;

        if (X == 0 && Y == 0) {
            break;
        }

        course.clear();
        course.resize(Y, vector<int>(X));

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cin >> course[i][j];
            }
        }

        cout << countSlides(0, 0) << endl;
    }

    return 0;
}