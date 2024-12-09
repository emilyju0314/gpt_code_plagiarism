#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Train {
    string departure;
    string arrival;
};

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<Train> timetable(n);
        
        for (int i = 0; i < n; i++) {
            cin >> timetable[i].departure >> timetable[i].arrival;
        }
        
        sort(timetable.begin(), timetable.end(), [](const Train &a, const Train &b) {
            return a.departure < b.departure;
        });
        
        int minVehicles = 0;
        string lastArrival = "00:00:00";
        
        for (const Train &train : timetable) {
            if (train.departure >= lastArrival) {
                lastArrival = train.arrival;
            } else {
                minVehicles++;
            }
        }
        
        cout << minVehicles + 1 << endl;
    }
    
    return 0;
}