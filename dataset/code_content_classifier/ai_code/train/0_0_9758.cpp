#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<pair<int, pair<int, int>>> people;

    for(int i = 0; i < n; i++) {
        int x, v, t;
        cin >> x >> v >> t;
        people.push_back({x, {v, t}});
    }

    double left = 0, right = 1e6;

    for(int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        double bomb_pos = mid;

        double time_to_reach_0 = 1e18;
        double time_to_reach_106 = 1e18;
        
       
        for(auto person : people) {
            int x = person.first;
            int v = person.second.first;
            int t = person.second.second;

            double time_to_reach_target;
            
            if(t == 1 && x > mid) {
                time_to_reach_target = (x - mid) * 1.0 / (s - v);
            } else if(t == 2 && x < mid) {
                time_to_reach_target = (mid - x) * 1.0 / (s - v);
            } else {
                time_to_reach_target = abs(x - mid) * 1.0 / s;
            }

            if(t == 1) {
                time_to_reach_0 = min(time_to_reach_0, time_to_reach_target);
            } else {
                time_to_reach_106 = min(time_to_reach_106, time_to_reach_target);
            }
        }

        if(time_to_reach_0 + time_to_reach_106 <= mid) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << right << endl;

    return 0;
}