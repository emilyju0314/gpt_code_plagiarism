#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> depots(n);
        
        for(int i = 0; i < n; i++) {
            cin >> depots[i];
        }
        
        sort(depots.begin(), depots.end());

        long long distance = 0;
        for(int i = n-1; i >= 0; i -= k) {
            distance += 2 * depots[i];
        }
        
        // Adding absolute value of min depot position
        distance += abs(depots[0]);
        
        cout << distance << endl;
    }

    return 0;
}