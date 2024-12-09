#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> mixedArray(n);
    map<int, vector<int>> permutations;
    
    for (int i = 0; i < n; i++) {
        cin >> mixedArray[i];
        permutations[mixedArray[i]].push_back(i);
    }
    
    for (auto& perm : permutations) {
        if (perm.second.size() > perm.first) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    vector<int> result(n);
    int permNum = 1;
    
    for (auto& perm : permutations) {
        for (int idx : perm.second) {
            result[idx] = permNum;
            permNum++;
        }
    }
    
    cout << permutations.size() << endl;
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}