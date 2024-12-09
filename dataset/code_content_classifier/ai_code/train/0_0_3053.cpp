#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void generateCamels(int idx, int n, int t, vector<int>& points) {
    if (idx == n) {
        int up = 0, down = 0;
        for (int i = 1; i < n - 1; i++) {
            if (points[i-1] < points[i] && points[i] > points[i+1]) {
                up++;
            }
            if (points[i-1] > points[i] && points[i] < points[i+1]) {
                down++;
            }
        }
        if (up == t && down == t - 1) {
            count++;
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        points[idx] = i;
        generateCamels(idx + 1, n, t, points);
    }
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> points(n, 0);
    points[0] = 1;
    points[1] = 1;

    generateCamels(2, n, t, points);

    cout << count << endl;

    return 0;
}