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

        int min_height = *min_element(heights.begin(), heights.end());
        int max_height = *max_element(heights.begin(), heights.end());

        int min_ugliness = max_height - min_height;

        cout << min_ugliness << endl;
    }

    return 0;
}