#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prefixSum(200);

    for (int i = 1; i < 200; i++) {
        prefixSum[i] = prefixSum[i-1] + i;
    }

    int budget;

    while (cin >> budget && budget != 0) {
        int start = 1;
        int end = 1;

        while (prefixSum[end] < budget) {
            end++;
        }

        while (prefixSum[end] > budget) {
            end--;
        }

        cout << start << " " << end << endl;
    }

    return 0;
}