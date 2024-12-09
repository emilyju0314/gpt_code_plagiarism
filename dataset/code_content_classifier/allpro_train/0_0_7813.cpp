#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> operations;
    
    for(int i = 1; i <= n/2; i++) {
        operations.push_back({i, i + n/2});
    }
    
    cout << operations.size() << endl;
    for(auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}