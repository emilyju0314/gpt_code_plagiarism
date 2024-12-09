#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> pairs;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j]) {
                pairs.push_back({i, j});
                swap(a[i], a[j]);
            }
        }
    }
    
    for(int i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << pairs.size() << endl;
    for(auto p : pairs) {
        cout << p.first+1 << " " << p.second+1 << endl;
    }
    
    return 0;
}