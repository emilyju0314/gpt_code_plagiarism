#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Robot {
    double x, y, vx, vy;
};

double calculateDistance(Robot r1, Robot r2) {
    return sqrt(pow(r1.x - r2.x, 2) + pow(r1.y - r2.y, 2));
}

double calculateTransmissionPower(vector<Robot>& robots) {
    double totalPower = 0.0;
    int n = robots.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            totalPower += calculateDistance(robots[i], robots[j]);
        }
    }
    
    return totalPower;
}

int main() {
    int N, T;
    
    while (true) {
        cin >> N >> T;
        
        if (N == 0 && T == 0) {
            break;
        }
        
        vector<Robot> robots(N);
        
        for (int i = 0; i < N; i++) {
            cin >> robots[i].x >> robots[i].y >> robots[i].vx >> robots[i].vy;
        }
        
        double minTransmissionPower = calculateTransmissionPower(robots);
        cout << fixed << minTransmissionPower << endl;
    }
    
    return 0;
}