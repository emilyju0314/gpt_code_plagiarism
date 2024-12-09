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

    vector<pair<int, int>> operations;
    for(int i = 0; i < n-2; i++) {
        if(a[i] == 1) {
            a[i] = !a[i];
            a[i+1] = !a[i+1];
            a[i+2] = !a[i+2];
            operations.push_back({i+1, i+2});
            operations.push_back({i+1, i+3});
        }
    }

    bool allZero = true;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            allZero = false;
            break;
        }
    }

    if(allZero) {
        cout << "YES" << endl;
        cout << operations.size() << endl;
        for(auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}