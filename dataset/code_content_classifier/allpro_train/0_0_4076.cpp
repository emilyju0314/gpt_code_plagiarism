#include <iostream>
#include <vector>

using namespace std;

bool canReachDestinations(int n, int m, vector<int>& cities, vector<vector<int>>& trucks, int V) {
    for (int i = 0; i < m; i++) {
        int s = trucks[i][0];
        int f = trucks[i][1];
        int c = trucks[i][2];
        int r = trucks[i][3];

        int currCity = s;
        int currFuel = V;
        for (int j = s; j < f; j++) {
            int distance = cities[j] - cities[currCity-1];
            if (distance * c > currFuel) {
                currFuel = V;
                r--;
            }
            if (r < 0) {
                return false;
            }
            currFuel -= distance * c;
            currCity = j+1;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    vector<vector<int>> trucks(m, vector<int>(4));
    for (int i = 0; i < m; i++) {
        cin >> trucks[i][0] >> trucks[i][1] >> trucks[i][2] >> trucks[i][3];
    }

    int low = 0, high = cities[n-1] - cities[0];
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canReachDestinations(n, m, cities, trucks, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}