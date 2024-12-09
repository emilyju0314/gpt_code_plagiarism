#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> bridges(M);
    
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bridges[i] = {c, b};
    }
    
    sort(bridges.begin(), bridges.end());
    
    int max_time = -1;
    int current_time = 0;
    
    for(auto bridge : bridges) {
        int c = bridge.first;
        int b = bridge.second;
        
        if(b == N) {
            max_time = max(max_time, current_time);
        } else {
            current_time = c;
        }
    }
    
    cout << max_time << endl;

    return 0;
}