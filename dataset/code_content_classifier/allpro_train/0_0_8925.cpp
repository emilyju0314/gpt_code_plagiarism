#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, z;
    cin >> n >> z;

    vector<int> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int pairs = 0;
    int left = 0, right = n/2;
    for(int i = 0; i < n/2; i++) {
        while(right < n && points[right] - points[left] < z) {
            right++;
        }
        if(right < n) {
            pairs++;
            right++;
        }
        left++;
    }

    cout << pairs << endl;

    return 0;
}