#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    unordered_map<int, vector<int>> indices;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        indices[a[i]].push_back(i);
    }
    
    int segments = 1;
    for(auto it = indices.begin(); it != indices.end(); ++it) {
        vector<int> vals = it->second;
        for(int j = 0; j < vals.size() - 1; j++) {
            if(vals[j] + 1 != vals[j + 1]) {
                segments++;
            }
        }
    }
    
    cout << segments << endl;
    
    return 0;
}