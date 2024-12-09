#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n, S;
    cin >> n >> S;

    vector<Point> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].x >> cities[i].y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int area = abs((cities[j].x - cities[i].x) * (cities[k].y - cities[i].y) - (cities[k].x - cities[i].x) * (cities[j].y - cities[i].y));
                if (area == S) {
                    cout << "Yes" << endl;
                    cout << cities[i].x << " " << cities[i].y << endl;
                    cout << cities[j].x << " " << cities[j].y << endl;
                    cout << cities[k].x << " " << cities[k].y << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}