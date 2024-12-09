#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isBalancedTree(vector<int>& sequence, int start, int end) {
    if (start >= end) return true;

    int leftSum = 0, rightSum = 0;
    int mid = (end - start + 1) / 2;

    for (int i = start; i < start + mid; i++) {
        leftSum += sequence[i];
    }

    for (int i = start + mid; i < end; i++) {
        rightSum += sequence[i];
    }

    if (leftSum != rightSum) return false;

    return isBalancedTree(sequence, start, start + mid) && isBalancedTree(sequence, start + mid, end);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        int maxLeaves = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isBalancedTree(sequence, i, j + 1)) {
                    int numLeaves = (j - i + 1) / 2;
                    maxLeaves = max(maxLeaves, numLeaves);
                }
            }
        }

        cout << maxLeaves << endl;
    }

    return 0;
}