#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int a[n], b[n], tm[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> tm[i];
        }
        
        int current_time = 0, arrival_time = 0;
        
        for (int i = 0; i < n; i++) {
            int stay_time = ceil((double)(b[i] - a[i]) / 2);
            arrival_time = max(b[i], current_time + stay_time) + tm[i];
            current_time = arrival_time;
        }
        
        cout << arrival_time << endl;
    }
    
    return 0;
}