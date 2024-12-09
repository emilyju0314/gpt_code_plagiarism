#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        
        vector<pair<int, pair<int, int>>> camels;
        for(int i = 0; i < N; i++) {
            int K, L, R;
            cin >> K >> L >> R;
            camels.push_back({L, {K, R}});
        }
        
        sort(camels.begin(), camels.end(), greater<pair<int, pair<int, int>>>());
        
        long long total_happiness = 0;
        long long current_sum = 0;
        
        for(int i = 0; i < N; i++) {
            current_sum += camels[i].second.second;
            if(camels[i].second.first < i+1) {
                current_sum += (camels[i].first - camels[i].second.second);
            }
            total_happiness = max(total_happiness, current_sum);
        }
        
        cout << total_happiness << endl;
    }
    
    return 0;
}