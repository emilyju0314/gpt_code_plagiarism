#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const int INF = 1000000000;

int main() {
    int n, m, p;
    
    while (true) {
        cin >> n >> m >> p;
        
        if (n == 0 && m == 0 && p == 0) {
            break;
        }
        
        vector<vector<pair<int, int>>> graph(n);
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        
        for (int i = 0; i < p; i++) {
            int target;
            cin >> target;
            
            vector<double> prob(n, 0.0);
            prob[0] = 1.0;
            
            priority_queue<pair<double, int>> pq;
            pq.push(make_pair(1.0, 0));
            
            while (!pq.empty()) {
                double cur_prob = pq.top().first;
                int cur_node = pq.top().second;
                pq.pop();
                
                if (cur_node == target) {
                    prob[target] = cur_prob;
                    break;
                }
                
                for (auto neighbor : graph[cur_node]) {
                    int next_node = neighbor.first;
                    int weight = neighbor.second;
                    
                    if (prob[cur_node] * weight > prob[next_node]) {
                        prob[next_node] = prob[cur_node] * weight;
                        pq.push(make_pair(prob[next_node], next_node));
                    }
                }
            }
            
            cout << fixed;
            cout << setprecision(8) << prob[target] << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}