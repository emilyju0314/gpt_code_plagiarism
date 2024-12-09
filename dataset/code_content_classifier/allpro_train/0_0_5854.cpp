#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;

    map<string, vector<string>> trips;
    int total_cost = 0;

    for (int i = 0; i < n; i++) {
        string start, end;
        cin >> start >> end;

        if(trips.find(start) == trips.end()) {
            trips[start] = vector<string>{end};
        } else {
            trips[start].push_back(end);
        }

        if(trips.find(end) == trips.end()) {
            trips[end] = vector<string>{start};
        } else {
            trips[end].push_back(start);
        }

        total_cost += a;
    }

    for(auto it = trips.begin(); it != trips.end(); it++) {
        vector<string> stops = it->second;
        string curr_stop = it->first;

        if(stops.size() > 1) {
            for(int i = 1; i < stops.size(); i++) {
                if(total_cost + b - a <= f) {
                    total_cost = f;
                    break;
                } else {
                    total_cost += b - a;
                }
            }
        }
    }

    cout << total_cost << endl;

    return 0;
}