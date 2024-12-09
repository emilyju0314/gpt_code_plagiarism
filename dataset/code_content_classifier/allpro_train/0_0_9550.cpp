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

        vector<int> heights(n);
        for(int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        long long operations = 0;
        int max_height = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(heights[i] < max_height) {
                operations += max_height - heights[i];
            } else {
                max_height = heights[i];
            }
        }

        cout << operations << endl;
    }

    return 0;
}