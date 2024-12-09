#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> colors(n);
    int currentColor = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i]; j++) {
            colors[i].push_back(currentColor);
            currentColor = (currentColor % k) + 1;
        }
    }

    bool possible = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(colors[i].size() != colors[j].size()) {
                possible = false;
                break;
            }
        }
    }

    if(!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < colors[i].size(); j++) {
                cout << colors[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}