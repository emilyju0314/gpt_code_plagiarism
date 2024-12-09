#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<int> items;
    for(int i = 1; i <= m; i++) {
        bool found = false;
        for(int j = 0; j < n; j++) {
            if(i == weights[j]) {
                found = true;
                break;
            }
        }
        if(found) items.push_back(i);
    }

    if(items.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << items.size() << endl;
        for(int num : items) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}