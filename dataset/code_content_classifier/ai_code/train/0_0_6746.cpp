#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<string, pair<int, string>> orders;
unordered_map<string, int> indegree;

int main() {
    int N;
    
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        orders.clear();
        indegree.clear();
        
        for (int i = 0; i < N; i++) {
            string name, sup;
            int day1, day2;
            cin >> name >> day1 >> sup >> day2;
            orders[name] = make_pair(day1, sup);
            indegree[sup]++;
        }
        
        queue<string> q;
        
        for (auto entry : orders) {
            if (indegree.find(entry.first) == indegree.end()) {
                q.push(entry.first);
            }
        }
        
        int total_days = 0;
        
        while (!q.empty()) {
            string tool = q.front();
            q.pop();
            
            total_days = max(total_days, orders[tool].first);
            
            for (auto entry : orders) {
                if (entry.second.second == tool) {
                    entry.second.first += orders[tool].second;
                    indegree[entry.first]--;
                    if (indegree[entry.first] == 0) {
                        q.push(entry.first);
                    }
                }
            }
        }
        
        cout << total_days << endl;
    }
    
    return 0;
}