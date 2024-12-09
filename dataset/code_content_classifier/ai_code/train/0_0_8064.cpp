#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<int> router_spots;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            router_spots.push_back(i);
        }
    }
    
    long long total_cost = 0;
    for(int i = 0; i < router_spots.size(); i++) {
        int room_num = router_spots[i];
        total_cost += room_num + 1;
        
        int start = max(0, room_num - k);
        int end = min(n - 1, room_num + k);
        
        if(i + 1 < router_spots.size()) {
            end = min(end, router_spots[i + 1] - k);
        }
        
        total_cost += max(0, end - start);
    }
    
    cout << total_cost << endl;
    
    return 0;
}