#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    int minVal = INT_MAX;
    int minIdx1 = -1, minIdx2 = -1;
    int dist = n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] < minVal) {
            minVal = nums[i];
            minIdx1 = i;
            minIdx2 = -1;
            dist = n;
        } else if (nums[i] == minVal) {
            if (minIdx2 == -1) {
                minIdx2 = i;
                dist = min(dist, minIdx2 - minIdx1);
            } else {
                minIdx1 = minIdx2;
                minIdx2 = i;
                dist = min(dist, minIdx2 - minIdx1);
            }
        }
    }

    cout << dist << endl;

    return 0;
}