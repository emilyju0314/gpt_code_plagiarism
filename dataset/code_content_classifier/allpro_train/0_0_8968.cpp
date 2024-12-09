#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cin >> m;
    vector<vector<int>> additions(m, vector<int>(3));
    for(int i = 0; i < m; i++) {
        cin >> additions[i][0] >> additions[i][1] >> additions[i][2];
    }

    vector<int> segments(n, 1);
    int max_width = 1;

    for(int i = 0; i < m; i++) {
        int left = additions[i][0] - 1;
        int right = additions[i][1] - 1;
        
        for(int j = left; j <= right; j++) {
            heights[j] += additions[i][2];
        }

        vector<int> increasing(n, 1);
        vector<int> decreasing(n, 1);

        for(int j = 1; j < n; j++) {
            if(heights[j] > heights[j-1]) {
                increasing[j] = increasing[j-1] + 1;
            }
        }

        for(int j = n-2; j >= 0; j--) {
            if(heights[j] > heights[j+1]) {
                decreasing[j] = decreasing[j+1] + 1;
            }
        }

        for(int j = left; j <= right; j++) {
            segments[j] = increasing[j] + decreasing[j] - 1;
            max_width = max(max_width, segments[j]);
        }

        cout << max_width << endl;
    }

    return 0;
}