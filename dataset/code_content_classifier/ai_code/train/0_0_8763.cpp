#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

bool isInsideTriangle(Point a, Point b, Point c, Point d) {
    int ABC = abs((a.x - c.x)*(b.y - a.y) - (a.x - b.x)*(c.y - a.y));
    int ABD = abs((a.x - b.x)*(d.y - a.y) - (a.x - d.x)*(b.y - a.y));
    int ACD = abs((a.x - d.x)*(c.y - a.y) - (a.x - c.x)*(d.y - a.y));
    int BCD = abs((b.x - c.x)*(d.y - b.y) - (b.x - d.x)*(c.y - b.y));

    int ABCD = ABC + ABD + ACD + BCD;

    if (ABCD == ABC + ABD + ACD + BCD) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Point> redPoints(N);
    vector<Point> bluePoints(M);

    for (int i = 0; i < N; i++) {
        cin >> redPoints[i].x >> redPoints[i].y;
    }

    for (int i = 0; i < M; i++) {
        cin >> bluePoints[i].x >> bluePoints[i].y;
    }

    int count = 0;
    // check all combinations of 3 red points
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                bool validTriangle = true;
                for (int l = 0; l < M; l++) {
                    if (isInsideTriangle(redPoints[i], redPoints[j], redPoints[k], bluePoints[l])) {
                        validTriangle = false;
                        break;
                    }
                }
                if (validTriangle) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}