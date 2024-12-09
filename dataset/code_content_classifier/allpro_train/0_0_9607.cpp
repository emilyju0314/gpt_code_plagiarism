#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct LineSegment {
    int x1, y1, x2, y2;
};

bool isOnSameSide(LineSegment wall, int x, int y) {
    return ((wall.x2 - wall.x1) * (y - wall.y1) - (wall.y2 - wall.y1) * (x - wall.x1)) >= 0;
}

bool doesIntersect(LineSegment wall, int x1, int y1, int x2, int y2) {
    return isOnSameSide(wall, x1, y1) != isOnSameSide(wall, x2, y2);
}

bool isValidAcceleration(vector<pair<int, int>> accList) {
    for (int i = 0; i < accList.size(); i++) {
        if (accList[i].first < -1 || accList[i].first > 1 || accList[i].second < -1 || accList[i].second > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<LineSegment> innerWall, outerWall;
    int x, y;
    LineSegment tempWall;

    // Input course configuration
    while (true) {
        cin >> x;
        if (x == 99999) break;

        tempWall.x1 = x;
        cin >> y;
        tempWall.y1 = y;

        cin >> x;
        cin >> y;
        tempWall.x2 = x;
        tempWall.y2 = y;

        innerWall.push_back(tempWall);
    }

    while (true) {
        cin >> x;
        if (x == 99999) break;

        tempWall.x1 = x;
        cin >> y;
        tempWall.y1 = y;

        cin >> x;
        cin >> y;
        tempWall.x2 = x;
        tempWall.y2 = y;

        outerWall.push_back(tempWall);
    }

    while (true) {
        int startX, startY;
        cin >> startX;
        if (startX == 99999) break;

        cin >> startY;

        double lapTime;
        cin >> lapTime;

        vector<pair<int, int>> accelerationList;
        int ax, ay;

        while (true) {
            cin >> ax;
            if (ax == 99999) break;
            cin >> ay;

            accelerationList.push_back({ax, ay});
        }

        if (accelerationList.size() != ceil(lapTime)) {
            cout << "NG" << endl;
            continue;
        }

        bool crashed = false;
        bool crossedStartLine = false;
        int prevX = startX, prevY = startY;
        for (int i = 0; i < accelerationList.size(); i++) {
            int vx = 0, vy = 0;
            if (i > 0) {
                vx = accelerationList[i-1].first;
                vy = accelerationList[i-1].second;
            }
            vx += accelerationList[i].first;
            vy += accelerationList[i].second;

            if (abs(vx) > 1 || abs(vy) > 1) {
                crashed = true;
                break;
            }

            int nextX = prevX + vx, nextY = prevY + vy;
            for (LineSegment wall : innerWall) {
                if (doesIntersect(wall, prevX, prevY, nextX, nextY)) {
                    crashed = true;
                    break;
                }
            }
            if (crashed) break;
            
            for (LineSegment wall : outerWall) {
                if (doesIntersect(wall, prevX, prevY, nextX, nextY)) {
                    crashed = true;
                    break;
                }
            }
            if (crashed) break;

            prevX = nextX;
            prevY = nextY;

            if (prevY == outerWall[0].y1) {
                crossedStartLine = true;
                break;
            }
        }

        if (crashed || !crossedStartLine) {
            cout << "NG" << endl;
        } else {
            cout << "OK" << endl;
        }
    }

    return 0;
}