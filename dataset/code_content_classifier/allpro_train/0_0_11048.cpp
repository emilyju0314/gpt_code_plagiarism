#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tangerines(n);
    for (int i = 0; i < n; i++) {
        cin >> tangerines[i];
    }

    int max_joy = 0;
    for (int i = 0; i < n; i++) {
        int parts = (tangerines[i] + k - 1) / k;
        int joy = (parts * k >= tangerines[i]) ? tangerines[i] : -1;
        
        max_joy = max(max_joy, joy);
    }

    cout << max_joy << endl;

    return 0;

}