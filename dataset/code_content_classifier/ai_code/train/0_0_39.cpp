#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // number of circles

    vector<pair<int, int>> centers; // stores the coordinates of the centers of circles
    vector<int> radii; // stores the radii of the circles

    for(int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        centers.push_back(make_pair(x, y));
        radii.push_back(r);
    }

    cout << "t" << endl; // f(t) function

    cout << "abs(";
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            cout << "-";
        }
        cout << "(t-" << centers[i].first << ")*(t-" << centers[i].first << ")";
        if(i < n-1) {
            cout << "+";
        }
    }
    cout << ")";

    return 0;
}