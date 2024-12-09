#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkNonIntersectingSums(vector<int>& b) {
    unordered_map<int, pair<int, int>> sumIndices;
    int n = b.size();
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += (1 << b[j]);
            if(sumIndices.find(sum) != sumIndices.end()) {
                pair<int, int> index = sumIndices[sum];
                if(index.second != i && index.second + 1 != j) {
                    return true;
                }
            }
            sumIndices[sum] = make_pair(i, j);
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        if(checkNonIntersectingSums(b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}