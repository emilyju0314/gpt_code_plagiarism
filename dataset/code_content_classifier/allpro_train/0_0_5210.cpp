#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int numAlignments = 0;
    while(true) {
        vector<int> newHeights = heights;

        int changed = 0;
        for(int i = 1; i < n - 1; i++) {
            int medianValue = max(min(heights[i-1], heights[i]), min(max(heights[i-1], heights[i]), heights[i+1]));
            if(medianValue != heights[i]) {
                newHeights[i] = medianValue;
                changed++;
            }
        }

        if(changed == 0) {
            break;
        } else {
            numAlignments++;
            heights = newHeights;
        }
    }

    cout << numAlignments << endl;
    for(int i = 0; i < n; i++) {
        cout << heights[i] << " ";
    }
    cout << endl;

    return 0;
}