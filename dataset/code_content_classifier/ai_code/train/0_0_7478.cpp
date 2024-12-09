#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> dirtyStairs;
    for (int i = 0; i < m; i++) {
        int stair;
        cin >> stair;
        dirtyStairs.insert(stair);
    }

    if (dirtyStairs.count(1) || dirtyStairs.count(n)) {
        cout << "NO" << endl;
    } else {
        bool canReachEnd = true;
        for (int i = 1; i <= n-2; i++) {
            if (dirtyStairs.count(i) && dirtyStairs.count(i+1) && dirtyStairs.count(i+2)) {
                canReachEnd = false;
                break;
            }
        }

        if (canReachEnd) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}