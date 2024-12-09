#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> parent(n+1, 0); // Initialize parent array with 0
    int changes = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == i+1) {
            parent[i+1] = i+1;
        } else {
            parent[i+1] = a[i];
            changes++;
        }
    }

    if(changes == 0) {
        cout << "0" << endl;
    } else {
        cout << changes << endl;

        // Find the vertex r that equals its parent
        int r;
        for(int i = 1; i <= n; i++) {
            if(i == parent[i]) {
                r = i;
                break;
            }
        }

        // Print the valid sequence after changes
        for(int i = 1; i <= n; i++) {
            if(i == r) {
                cout << r << " ";
            } else {
                cout << parent[i] << " ";
            }
        }
    }

    return 0;
}