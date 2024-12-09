#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    unordered_map<int, int> colors;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int color = 1;
    bool possible = true;

    for(int i = 0; i < n; i++) {
        if(colors.find(a[i]) != colors.end()) {
            a[i] = colors[a[i]];
        } else {
            colors[a[i]] = color;
            a[i] = color;
            color++;
            if(color > k) {
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
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}