#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool canReach(set<pair<int, int>>& intervals, int a, int b) {
    for(auto interval : intervals) {
        if((interval.first < a && a < interval.second) || (interval.first < b && b < interval.second)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> intervals;

    for(int i = 0; i < n; i++) {
        int type, x, y;
        cin >> type >> x >> y;

        if(type == 1) {
            intervals.insert(make_pair(x, y));
        } else {
            if(canReach(intervals, x, y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}