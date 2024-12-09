#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    int n, m;
    cin >> n >> m;

    vector<int> numRidesBuses(n);
    vector<int> numRidesTrolleys(m);

    for(int i=0; i<n; i++) {
        cin >> numRidesBuses[i];
    }

    for(int i=0; i<m; i++) {
        cin >> numRidesTrolleys[i];
    }

    int cost = 0;

    cost = min(c1 * accumulate(numRidesBuses.begin(), numRidesBuses.end(), 0),
               c2 * accumulate(numRidesBuses.begin(), numRidesBuses.end(), 0));
    
    cost = min(cost, c3 * accumulate(numRidesTrolleys.begin(), numRidesTrolleys.end(), 0));
    cost = min(cost, c4 * (accumulate(numRidesBuses.begin(), numRidesBuses.end(), 0) + 
                           accumulate(numRidesTrolleys.begin(), numRidesTrolleys.end(), 0)));

    cout << cost << endl;

    return 0;
}