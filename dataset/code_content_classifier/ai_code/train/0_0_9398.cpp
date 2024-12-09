#include <iostream>
#include <vector>

using namespace std;

struct Robot {
    int dir;
    int x;
    int y;
    int len;
};

bool isPointInTriangle(Robot robot, int targetX, int targetY) {
    switch (robot.dir) {
        case 1:
            if (targetX >= robot.x && targetX <= robot.x + robot.len && targetY >= robot.y && targetY <= robot.y + robot.len) {
                return true;
            }
            break;
        case 2:
            if (targetX >= robot.x && targetX <= robot.x + robot.len && targetY >= robot.y - robot.len && targetY <= robot.y) {
                return true;
            }
            break;
        case 3:
            if (targetX >= robot.x - robot.len && targetX <= robot.x && targetY >= robot.y && targetY <= robot.y + robot.len) {
                return true;
            }
            break;
        case 4:
            if (targetX >= robot.x - robot.len && targetX <= robot.x && targetY >= robot.y - robot.len && targetY <= robot.y) {
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<Robot> robots;
    for (int i = 0; i < Q; i++) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            Robot newRobot;
            cin >> newRobot.dir >> newRobot.x >> newRobot.y >> newRobot.len;
            robots.push_back(newRobot);
        } else {
            int x, y;
            cin >> x >> y;
            int count = 0;
            for (Robot robot : robots) {
                if (isPointInTriangle(robot, x, y)) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}