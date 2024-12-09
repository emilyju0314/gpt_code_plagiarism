#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    
    while (true) {
        cin >> N;
        
        if (N == 0) {
            break;
        }
        
        vector<pair<int, int>> velocities(N);
        for (int i = 0; i < N; i++) {
            cin >> velocities[i].first >> velocities[i].second;
        }
        
        int targetX, targetY;
        cin >> targetX >> targetY;
        
        bool reached = false;
        
        for (int i = 1; i < (1 << N); i++) {
            int currX = 0, currY = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    currX += velocities[j].first;
                    currY += velocities[j].second;
                }
            }
            double t = sqrt(pow(targetX - currX, 2) + pow(targetY - currY, 2)) / sqrt(9.8);
            if (abs(targetY - currY - 0.5 * 9.8 * t * t) <= 1e-6) {
                reached = true;
                break;
            }
        }
        
        if (reached) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}