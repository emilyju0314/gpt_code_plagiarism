#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string time;
        cin >> time;

        stringstream ss(time);
        char temp;
        int h, m;
        ss >> h >> temp >> m;

        double angle = abs(30.0 * (h % 12 + m / 60.0) - 6.0 * m);
        
        if (angle >= 0.0 && angle < 30.0) {
            cout << "alert" << endl;
        } else if (angle >= 90.0 && angle <= 180.0) {
            cout << "far" << endl;
        } else {
            cout << "warning" << endl;
        }
    }

    return 0;
}