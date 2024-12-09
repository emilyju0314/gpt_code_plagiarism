#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Line {
    int dest;
    int distance;
    int company;
};

struct FareInterval {
    int distance;
    int fare;
};

int main() {
    int n, m, c, s, g;
    
    while (cin >> n >> m >> c >> s >> g) {
        if (n == 0 && m == 0 && c == 0 && s == 0 && g == 0) {
            break;
        }
        
        vector<vector<Line>> graph(n+1);
        vector<vector<FareInterval>> fareTables(c+1);
        
        for (int i = 0; i < m; i++) {
            int x, y, d, comp;
            cin >> x >> y >> d >> comp;
            graph[x].push_back({y, d, comp});
            graph[y].push_back({x, d, comp});
        }
        
        for (int i = 1; i <= c; i++) {
            int p;
            cin >> p;
            int prev_dist = 0, prev_fare = 0;
            for (int j = 0; j < p; j++) {
                int dist, fare;
                cin >> dist;
                cin >> fare;
                fareTables[i].push_back({dist, fare});
            }
        }
        
        vector<vector<int>> dist(n+1, vector<int>(c+1, INT_MAX));
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>> pq;
        
        dist[s][1] = 0;
        pq.push({{0, 1}, s});
        
        while (!pq.empty()) {
            int cur_dist = pq.top().first.first;
            int cur_company = pq.top().first.second;
            int cur_node = pq.top().second;
            pq.pop();
            
            if (cur_node == g) {
                cout << cur_dist << endl;
                break;
            }
            
            if (cur_dist > dist[cur_node][cur_company]) {
                continue;
            }
            
            for (const Line& line : graph[cur_node]) {
                int new_dist = cur_dist + line.distance;
                int new_company = line.company;
                
                if (cur_company != new_company) {
                    for (const FareInterval& f : fareTables[new_company]) {
                        if (new_dist <= f.distance) {
                            int fare = dist[cur_node][cur_company] + f.fare;
                            if (fare < dist[line.dest][new_company]) {
                                dist[line.dest][new_company] = fare;
                                pq.push({{fare, new_company}, line.dest});
                            }
                            break;
                        }
                    }
                } else {
                    if (new_dist < dist[line.dest][new_company]) {
                        dist[line.dest][new_company] = new_dist;
                        pq.push({{new_dist, new_company}, line.dest});
                    }
                }
            }
        }
        
        if (dist[g][1] == INT_MAX) {
            cout << "-1" << endl;
        }
    }
    
    return 0;
}