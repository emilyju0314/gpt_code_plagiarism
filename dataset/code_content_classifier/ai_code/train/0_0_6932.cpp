#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    map<int, vector<pair<int, int>>> sumsToIndices;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += a[j];
            sumsToIndices[sum].push_back({i, j});
        }
    }
    
    int maxBlocks = 0;
    vector<pair<int, int>> maxBlockIndices;
    for(auto entry : sumsToIndices) {
        if(entry.second.size() > maxBlocks) {
            maxBlocks = entry.second.size();
            maxBlockIndices = entry.second;
        }
    }
    
    cout << maxBlockIndices.size() << endl;
    for(auto block: maxBlockIndices) {
        cout << block.first+1 << " " << block.second+1 << endl;
    }
    
    return 0;
}