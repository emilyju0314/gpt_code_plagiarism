#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    
    while (true) {
        cin >> n;
        if (n == 0) break;
        
        cin >> m;
        
        vector<pair<int, int>> sites(n);
        for (int i = 0; i < n; i++) {
            sites[i] = make_pair(0, 0);
        }
        
        vector<pair<pair<int, int>, int>> connections(m);
        for (int i = 0; i < m; i++) {
            int a, b, d;
            char comma;
            cin >> a >> comma >> b >> comma >> d;
            connections[i] = make_pair(make_pair(a, b), d);
        }
        
        sort(connections.begin(), connections.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b){
            return a.second < b.second;
        });
        
        int minLanterns = 0;
        for (int i = 0; i < m; i++) {
            int a = connections[i].first.first;
            int b = connections[i].first.second;
            int d = connections[i].second;
            if (sites[a].first == 0 || sites[b].first == 0 || sites[a].second != sites[b].second) {
                minLanterns++;
                int val = max(sites[a].first, sites[b].first) + 1;
                for (int j = 0; j < n; j++) {
                    if (sites[j].first == sites[a].first && sites[j].second == sites[a].second) {
                        sites[j] = make_pair(val, sites[b].second);
                    }
                }
            }
        }
        
        cout << minLanterns * 100 << endl;
    }
    
    return 0;
}