#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int minOps = 0;
    vector<pair<int, pair<int, int>>> operations;
    
    for (int i = 1; i < n; i++) {
        int diff = abs(a[i] - a[i-1]);
        if (diff != 0) {
            if (a[i] > a[i-1]) {
                a[i] -= diff;
                operations.push_back(make_pair(2, make_pair(i+1, i)));
            } else {
                a[i] += diff;
                operations.push_back(make_pair(1, make_pair(i+1, i)));
            }
            minOps++;
        }
    }
    
    cout << minOps << endl;
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i].first << " " << operations[i].second.first << " " << operations[i].second.second << endl;
    }
    
    return 0;
}