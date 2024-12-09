#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> smallArrays(n);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        smallArrays[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> smallArrays[i][j];
        }
    }

    vector<int> bigArray;
    for (int i = 0; i < m; i++) {
        int index;
        cin >> index;
        bigArray.insert(bigArray.end(), smallArrays[index-1].begin(), smallArrays[index-1].end());
    }

    int maxSum = bigArray[0];
    int currentSum = bigArray[0];

    for (int i = 1; i < bigArray.size(); i++) {
        currentSum = max(bigArray[i], currentSum + bigArray[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}