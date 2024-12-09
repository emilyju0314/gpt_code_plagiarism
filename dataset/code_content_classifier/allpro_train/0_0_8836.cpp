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
    
    vector<pair<int, pair<int, int>>> operations;

    for(int i = 1; i < n; i++) {
        int x = i + 1 - a[i];
        if(x <= 0) {
            operations.push_back({1, {i, 1}});
            a[i] += 1;
            x = 1;
        }
        operations.push_back({1, {i, x}});
        a[i] += x;
    }
    
    cout << operations.size() << endl;
    for(auto op : operations) {
        cout << op.first << " " << op.second.first + 1 << " " << op.second.second << endl;
    }

    return 0;
}