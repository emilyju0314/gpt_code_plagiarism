#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<long long, pair<int, int>> mp;
    long long max_len = 0, start_idx = -1;
    
    for(int i = 0; i < n; i++) {
        long long num = arr[i];
        
        mp[num] = make_pair(mp[num - 1].first + 1, i);
        
        if(mp[num].first > max_len) {
            max_len = mp[num].first;
            start_idx = i;
        }
    }
    
    vector<int> result;
    while(max_len--) {
        result.push_back(start_idx-- + 1);
    }
    
    cout << result.size() << endl;
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    
    return 0;
}