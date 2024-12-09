#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int c = 0;
    vector<pair<int, int>> steps;

    for (int i = 0; i < n; i++) {
        int diff = abs(a[i] - b[i]);
        if (diff > 5) {
            cout << "-1" << endl;
            return 0;
        }

        if (diff > 0) {
            int add = (a[i] < b[i]) ? 1 : -1;
            c++;
            steps.push_back({i+1, add});
        }
    }

    cout << c << endl;
    for (int i = 0; i < c; i++) {
        cout << steps[i].first << " " << steps[i].second << endl;
    }

    return 0;
}