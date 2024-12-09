#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());

    int max_length = 1;
    int count = 1;
    int start = 0;
    int end = 0;

    for (int i = 1; i < n; i++) {
        if (heights[i] - heights[i - 1] <= 1) {
            count++;
            if (count > max_length) {
                max_length = count;
                end = i;
            }
        } else {
            count = 1;
        }
    }

    cout << max_length << endl;
    for (int i = start; i <= end; i++) {
        cout << heights[i] << " ";
    }
    cout << endl;
    
    return 0;
}