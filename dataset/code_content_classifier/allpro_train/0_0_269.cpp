#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> memory(n);
    for(int i = 0; i < n; i++) {
        cin >> memory[i].first >> memory[i].second;
    }

    sort(memory.begin(), memory.end());

    vector<int> ordering(n);
    for(int i = 0; i < n; i++) {
        ordering[i] = i + 1;
    }

    bool possible = true;
    for(int i = 0; i < n; i++) {
        if(ordering[i] < memory[i].first || ordering[i] > memory[i].second) {
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            cout << ordering[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
        for(int i = 0; i < n; i++) {
            cout << ordering[i] << " ";
        }
        cout << endl;
        for(int i = n - 1; i >= 0; i--) {
            cout << ordering[i] << " ";
        }
        cout << endl;
    }

    return 0;
}