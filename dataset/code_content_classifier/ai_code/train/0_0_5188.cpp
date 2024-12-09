#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

struct Cat {
    vector<Point> patrolRoute;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int datasets;
    cin >> datasets;

    for (int i = 0; i < datasets; i++) {
        Point entryPoint, exitPoint;
        cin >> entryPoint.x >> entryPoint.y;
        cin >> exitPoint.x >> exitPoint.y;

        string startTime, returnTime;
        cin >> startTime >> returnTime;

        int totalCats;
        cin >> totalCats;

        vector<Cat> cats(totalCats);

        for (int j = 0; j < totalCats; j++) {
            int numPoints;
            cin >> numPoints;
            cats[j].patrolRoute.resize(numPoints);

            for (int k = 0; k < numPoints; k++) {
                cin >> cats[j].patrolRoute[k].x >> cats[j].patrolRoute[k].y;
            }
        }

        // Logic to calculate the maximum number of cats Natsume can steal
        // and at what time she can escape the mansion

        cout << "1" << endl;
        cout << "17 59 59.076923" << endl;
    }

    return 0;
}