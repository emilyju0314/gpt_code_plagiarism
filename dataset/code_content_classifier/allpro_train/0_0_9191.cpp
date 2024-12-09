#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Friend {
    int arrival_time;
    int max_water;
    int cost_per_liter;

    Friend(int at, int mw, int cpl) : arrival_time(at), max_water(mw), cost_per_liter(cpl) {}
};

int main() {
    int q;
    cin >> q;

    while(q--) {
        int n, m, c, c0;
        cin >> n >> m >> c >> c0;

        vector<Friend> friends;
        for(int i = 0; i < n; i++) {
            int t, a, b;
            cin >> t >> a >> b;
            friends.push_back(Friend(t, a, b));
        }

        long long remaining_water = c0;
        int total_cost = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < m; i++) {
            for(auto friend : friends) {
                if(friend.arrival_time == i) {
                    pq.push({friend.cost_per_liter, friend.max_water});
                }
            }

            while(!pq.empty() && remaining_water < 1) {
                pair<int, int> top = pq.top();
                pq.pop();

                int cost = top.first;
                int water = top.second;

                int water_to_add = min(c - remaining_water, water);
                remaining_water += water_to_add;
                total_cost += cost * water_to_add;

                if(water > water_to_add) {
                    pq.push({cost, water - water_to_add});
                }
            }

            remaining_water -= 1;
            if(remaining_water < 0) {
                total_cost = -1;
                break;
            }
        }

        cout << total_cost << endl;
    }

    return 0;
}