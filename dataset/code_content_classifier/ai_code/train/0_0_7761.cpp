#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    unordered_map<int, int> index;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        index[a[i]] = i;
    }
    
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    vector<int> visited(n);
    int k = 0;
    vector<vector<int>> subsequences;
    
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        
        vector<int> subseq;
        
        int current = i;
        while (!visited[current]) {
            subseq.push_back(current);
            visited[current] = true;
            current = index[sorted_a[current]];
        }
        
        if (subseq.size() > 0) {
            k++;
            subsequences.push_back(subseq);
        }
    }
    
    cout << k << endl;
    for (int i = 0; i < k; ++i) {
        cout << subsequences[i].size() << " ";
        for (int j = 0; j < subsequences[i].size(); ++j) {
            cout << subsequences[i][j] + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}