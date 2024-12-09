#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    bool canCompleteWall = true;
    int min_height = *min_element(heights.begin(), heights.end());

    for(int i = 0; i < n; i++) {
        if(heights[i] > min_height) {
            if(i > 0 && heights[i-1] < heights[i]) {
                canCompleteWall = false;
                break;
            }
        }
    }

    if(canCompleteWall) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}