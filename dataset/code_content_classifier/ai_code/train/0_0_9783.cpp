#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    while (true) {
        cin >> n;
        
        if (n == 0) {
            break;
        }
        
        vector<vector<int>> schedules(n);
        for (int i = 0; i < n; i++) {
            int days;
            cin >> days;
            vector<int> schedule(days);
            for (int j = 0; j < days; j++) {
                cin >> schedule[j];
            }
            schedules[i] = schedule;
        }
        
        vector<int> count(31, 0);
        int mapCount = 0;
        int days = 1;
        
        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                for (int day : schedules[i]) {
                    if (day == days) {
                        mapCount++;
                        if (mapCount == n) {
                            found = true;
                            break;
                        }
                    }
                }
            }
            
            if (found) {
                break;
            }

            days++;
            if (days > 30) {
                cout << -1 << endl;
                break;
            }
        }
        
        if (mapCount == n) {
            cout << days << endl;
        }
    }
    
    return 0;
}