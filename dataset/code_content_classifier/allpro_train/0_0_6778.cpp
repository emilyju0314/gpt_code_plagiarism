#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> calls;
    
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            calls.push_back({start+1, i+1});
            start = i+1;
        }
    }
    
    cout << calls.size() << endl;
    for (auto c : calls) {
        cout << c.first << " " << c.second << endl;
    }
    
    return 0;
}