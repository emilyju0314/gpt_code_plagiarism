#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;
    
    while (true) {
        cin >> T;
        
        if (T == 0) {
            break;
        }
        
        vector<int> cycle(T);
        for (int i = 0; i < T; i++) {
            cin >> cycle[i];
        }
        
        cin >> N;
        
        vector<pair<int, int>> interviews(N);
        for (int i = 0; i < N; i++) {
            int day, start_hour;
            cin >> day >> start_hour;
            interviews[i] = make_pair(day, start_hour);
        }
        
        int min_caffeine = 0;
        int current_day = 1; // Start on the first day of the cycle
        
        for (int i = 0; i < N; i++) {
            int interview_day = interviews[i].first;
            int start_hour = interviews[i].second;
            
            if (interview_day < current_day) {
                min_caffeine += T - current_day + interview_day;
            } else {
                min_caffeine += interview_day - current_day;
            }
            
            current_day = interview_day;
            
            int remaining_sleep = cycle[current_day % T] - 1;
            if (remaining_sleep < 0) {
                remaining_sleep += T;
            }
            
            if (remaining_sleep != 0) {
                min_caffeine += 1; // Take caffeine to reset the sleep cycle
                current_day++;
            }
        }
        
        cout << min_caffeine << endl;
    }
    
    return 0;
}