#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool isInRange(Point p1, Point p2, int range) {
    return abs(p1.x - p2.x) <= range && abs(p1.y - p2.y) <= range;
}

int main() {
    while (true) {
        int px, py;
        cin >> px >> py;
        
        if (px == 0 && py == 0) break;
        
        int n;
        cin >> n;
        
        vector<Point> sprinklerLocations(n);
        for (int i = 0; i < n; i++) {
            cin >> sprinklerLocations[i].x >> sprinklerLocations[i].y;
        }
        
        bool alive = false;
        
        do {
            Point currentPos = {px, py};
            bool reachedEnd = false;
            
            for (int i = 0; i < n; i++) {
                if (isInRange(currentPos, sprinklerLocations[i], 1)) {
                    currentPos = sprinklerLocations[i];
                } else {
                    reachedEnd = true;
                    break;
                }
            }
            
            if (reachedEnd) continue;
            
            alive = true;
            break;
        } while (next_permutation(sprinklerLocations.begin(), sprinklerLocations.end()));
        
        if (alive) {
            cout << "OK" << endl;
        } else {
            cout << "NA" << endl;
        }
    }

    return 0;
}