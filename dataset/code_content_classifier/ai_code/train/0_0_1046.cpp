#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<pair<int, char>>> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        char L;
        cin >> u >> v >> L;
        graph[u].push_back({v, L});
        graph[v].push_back({u, L});
    }
    
    int Q;
    cin >> Q;
    
    unordered_map<string, int> colorCount;
    
    for (int i = 0; i < Q; i++) {
        int u, v;
        string S;
        cin >> u >> v >> S;
        
        int totalCount = 0;
        
        for (int j = 0; j < S.length(); j++) {
            colorCount.clear();
            string currentSubarray = "";
            for (int k = j; k < S.length(); k++) {
                currentSubarray += S[k];
                colorCount[currentSubarray]++;
            }
            
            int count = 0;
            for (auto& entry : colorCount) {
                string currentSubarrayCount = entry.first;
                int currentCount = entry.second;
                for (auto& neighbor : graph[u]) {
                    if (neighbor.second == currentSubarrayCount[0]) {
                        count += currentCount;
                        totalCount += count;
                    }
                }
            }
        }
        
        cout << totalCount << endl;
    }
    
    return 0;
}