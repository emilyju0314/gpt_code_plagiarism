#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string l, r;
    cin >> l >> r;
    
    vector<pair<int, int>> pairs;
    
    vector<int> left_indices, right_indices;
    
    for (int i = 0; i < n; i++) {
        if (l[i] == r[i]) {
            pairs.push_back(make_pair(i+1, i+1));
        } else if (l[i] == '?') {
            left_indices.push_back(i+1);
        } else if (r[i] == '?') {
            right_indices.push_back(i+1);
        }
    }
    
    for (int i = 0; i < min(left_indices.size(), right_indices.size()); i++) {
        pairs.push_back(make_pair(left_indices[i], right_indices[i]));
    }
    
    cout << pairs.size() << endl;
    for (auto p : pairs) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}