#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

bool isObstacle(int x, int y, const vector<Point>& obstacles) {
    for (const auto& obstacle : obstacles) {
        if (obstacle.x == x && obstacle.y == y) {
            return true;
        }
    }
    return false;
}

int main() {
    int w, h, gx, gy, n;
    cin >> w >> h >> gx >> gy >> n;

    vector<Point> obstacles(n);
    for (int i = 0; i < n; i++) {
        cin >> obstacles[i].x >> obstacles[i].y;
    }

    string directions;
    cin >> directions;

    int ans = 0;

    for (int x = 1; x <= w; x++) {
        for (int y = 1; y <= h; y++) {
            for (char direction : {'U', 'D', 'L', 'R'}) {
                int currX = x, currY = y;
                bool reached = false;

                for (char d : directions) {
                    if (d == 'L') {
                        if (direction == 'U') {
                            direction = 'L';
                        } else if (direction == 'D') {
                            direction = 'R';
                        } else if (direction == 'L') {
                            direction = 'D';
                        } else if (direction == 'R') {
                            direction = 'U';
                        }
                    } else if (d == 'R') {
                        if (direction == 'U') {
                            direction = 'R';
                        } else if (direction == 'D') {
                            direction = 'L';
                        } else if (direction == 'L') {
                            direction = 'U';
                        } else if (direction == 'R') {
                            direction = 'D';
                        }
                    } else {
                        if (direction == 'U') {
                            currY--;
                        } else if (direction == 'D') {
                            currY++;
                        } else if (direction == 'L') {
                            currX--;
                        } else if (direction == 'R') {
                            currX++;
                        }
                    }

                    if (currX < 1 || currX > w || currY < 1 || currY > h || isObstacle(currX, currY, obstacles)) {
                        break;
                    }

                    if (currX == gx && currY == gy) {
                        reached = true;
                        break;
                    }
                }

                if (reached) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}