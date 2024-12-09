#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> mappings;
    vector<pair<int, int>> engineers;
    
    for(int i = 0; i < N; i++) {
        int curr, desired;
        cin >> curr >> desired;
        
        engineers.push_back(make_pair(curr, desired));
        mappings[curr]++;
        mappings[desired]++;
    }
    
    long long ans = 1;
    for(auto it = mappings.begin(); it != mappings.end(); it++) {
        int count = it->second;
        while(count > 1) {
            ans = (ans * count) % MOD;
            count--;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}