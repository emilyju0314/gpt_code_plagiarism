#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, len, k;
    cin >> n >> len;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> k;

    long long maxSum = 0;
    for (int i = 0; i < n - len + 1; i++) {
        vector<int> temp = a;
        vector<int> negIndices;
        
        for (int j = 0; j < len; j++) {
            if (temp[i + j] < 0) {
                negIndices.push_back(i + j);
            }
        }

        sort(negIndices.begin(), negIndices.end(), [&](int a, int b) {
            return temp[a] < temp[b];
        });

        int numNeg = min(k, (int)negIndices.size());
        for (int j = 0; j < numNeg; j++) {
            temp[negIndices[j]] *= -1;
        }

        long long sum = 0;
        for (int j = i; j < i + len; j++) {
            sum += abs(temp[j]);
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
}