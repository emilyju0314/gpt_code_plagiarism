#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPowerOfTwo(int x) {
    return x && ((x & (x - 1)) == 0);
}

int main() {
    int n;
    cin >> n;

    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int maxSubsetSize = 1;
    int maxSubsetStart = points[0];

    for (int i = 0; i < n; i++) {
        for (int power = 1; ; power++) {
            int nextPoint = points[i] + (1 << power);
            if (binary_search(points.begin(), points.end(), nextPoint)) {
                int subsetSize = 2;
                int currPoint = nextPoint;

                while (true) {
                    subsetSize++;
                    currPoint += (1 << power);

                    if (binary_search(points.begin(), points.end(), currPoint)) {
                        maxSubsetSize = max(maxSubsetSize, subsetSize);
                        maxSubsetStart = points[i];
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }
    }

    cout << maxSubsetSize << endl;
    cout << maxSubsetStart;
    for (int i = 1; i < maxSubsetSize; i++) {
        cout << " " << maxSubsetStart + i*(1 << int(log2(i)));
    }
    cout << endl;

    return 0;
}