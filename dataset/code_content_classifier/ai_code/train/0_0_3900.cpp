#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

bool comparePoints(Point a, Point b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool isSafe(vector<Point>& engine1, vector<Point>& engine2) {
    sort(engine1.begin(), engine1.end(), comparePoints);
    sort(engine2.begin(), engine2.end(), comparePoints);
    
    vector<Point> powerField;
    
    for (int i = 0; i < engine1.size(); i++) {
        powerField.push_back(engine1[i]);
    }
    
    for (int i = 0; i < engine2.size(); i++) {
        powerField.push_back(engine2[i]);
    }
    
    vector<Point> newPowerField;
    
    for (int i = 0; i < powerField.size(); i++) {
        for (int j = i + 1; j < powerField.size(); j++) {
            newPowerField.push_back({(powerField[i].x + powerField[j].x) / 2, (powerField[i].y + powerField[j].y) / 2});
        }
    }
    
    for (int i = 0; i < newPowerField.size(); i++) {
        bool found = false;
        for (int j = 0; j < powerField.size(); j++) {
            if (newPowerField[i].x == powerField[j].x && newPowerField[i].y == powerField[j].y) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Point> engine1(n);
    vector<Point> engine2(m);
    
    for (int i = 0; i < n; i++) {
        cin >> engine1[i].x >> engine1[i].y;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> engine2[i].x >> engine2[i].y;
    }
    
    if (isSafe(engine1, engine2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}