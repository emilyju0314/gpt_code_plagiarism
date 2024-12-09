#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> alarms; // Pair of hours and minutes
    
    for(int i=0; i<n; i++) {
        string time;
        cin >> time;
        
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        
        alarms.push_back({hours, minutes});
    }
    
    sort(alarms.begin(), alarms.end());
    
    int max_sleep = 0;
    int start_sleep = alarms[0].first * 60 + alarms[0].second;
    
    for(int i=1; i<alarms.size(); i++) {
        int end_sleep = alarms[i].first * 60 + alarms[i].second;
        int sleep = end_sleep - start_sleep - 1; // Get the sleep time between alarms
        max_sleep = max(max_sleep, sleep);
        start_sleep = end_sleep;
    }
    
    // Handle the case where the last alarm to the first alarm is checked
    int end_sleep = 24*60 + alarms[0].first * 60 + alarms[0].second;
    int sleep = end_sleep - start_sleep - 1;
    max_sleep = max(max_sleep, sleep);
    
    int hh = max_sleep / 60;
    int mm = max_sleep % 60;
    
    cout << (hh < 10 ? "0" : "") << hh << ":" << (mm < 10 ? "0" : "") << mm << endl;
    
    return 0;
}