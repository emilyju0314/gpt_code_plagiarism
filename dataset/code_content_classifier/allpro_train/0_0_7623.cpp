#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, pair<int, int>>> robots;
    
    for(int i = 0; i < N; i++) {
        int x, r, q;
        cin >> x >> r >> q;
        robots.push_back({x, {r, q}});
    }
    
    sort(robots.begin(), robots.end());
    
    int totalPairs = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(robots[j].first - robots[i].first > robots[i].second.first) {
                break;
            }
            if(abs(robots[j].second.second - robots[i].second.second) <= K) {
                totalPairs++;
            }
        }
    }
    
    cout << totalPairs << endl;
    
    return 0;
}