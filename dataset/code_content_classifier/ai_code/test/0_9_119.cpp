#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> buildings(n);
        for(int i = 0; i < n; i++) {
            cin >> buildings[i];
        }

        sort(buildings.begin(), buildings.end());

        int minUgliness = INT_MAX;
        for(int i = 1; i < n; i++) {
            minUgliness = min(minUgliness, buildings[i] - buildings[i-1]);
        }

        cout << minUgliness << endl;
    }

    return 0;
}