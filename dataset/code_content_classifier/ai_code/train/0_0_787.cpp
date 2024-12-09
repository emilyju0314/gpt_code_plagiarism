#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, L;
    cin >> n >> L;

    vector<pair<int, int>> ranges(n);

    for (int i = 0; i < n; i++) {
        cout << "? " << i+1 << " 0" << endl;
        cout.flush();
        cin >> ranges[i].first;
    }

    int prev = 0;
    for (int i = 0; i < n; i++) {
        int next = ranges[i].first + L/n;
        cout << "? " << i+1 << " " << next << endl;
        cout.flush();
        cin >> ranges[i].second;
        prev = ranges[i].second;
    }

    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        cout << ranges[i].first << " " << ranges[i].second << endl;
    }

    return 0;
}