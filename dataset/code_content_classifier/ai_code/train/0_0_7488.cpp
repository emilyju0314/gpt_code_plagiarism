#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long long pairs = 0;
    for (int i = 0; i < n; i++) {
        int next_hill = (i + 1) % n;
        int max_height = max(heights[i], heights[next_hill]);
        int count = 1;

        while (count < n && heights[(i + count) % n] <= max_height) {
            count++;
            pairs++;
        }
    }

    cout << pairs << endl;

    return 0;
}