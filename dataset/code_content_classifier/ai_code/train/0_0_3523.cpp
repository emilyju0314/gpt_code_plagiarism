#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

bool compare_points(Point p1, Point p2) {
    return p1.x < p2.x;
}

bool canAssignShips(int R, int B, vector<Point>& rebels, vector<Point>& bases) {
    if (R != B) {
        return false; // Number of Rebel spaceships must be equal to number of bases
    }
    
    sort(rebels.begin(), rebels.end(), compare_points);
    sort(bases.begin(), bases.end(), compare_points);
    
    for (int i = 0; i < R; i++) {
        if (rebels[i].x == bases[i].x && rebels[i].y == bases[i].y) {
            return false; // Rebel spaceship and base cannot have the same coordinates
        }
    }
    
    return true;
}

int main() {
    int R, B;
    cin >> R >> B;
    
    vector<Point> rebels(R);
    vector<Point> bases(B);
    
    for (int i = 0; i < R; i++) {
        cin >> rebels[i].x >> rebels[i].y;
    }
    
    for (int i = 0; i < B; i++) {
        cin >> bases[i].x >> bases[i].y;
    }
    
    if (canAssignShips(R, B, rebels, bases)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}