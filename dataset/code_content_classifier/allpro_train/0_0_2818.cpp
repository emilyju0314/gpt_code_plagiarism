#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long prairiePartition(long long x) {
    long long sum = 0, powerOf2 = 1;
    while (sum < x) {
        sum += powerOf2;
        powerOf2 *= 2;
    }
    return powerOf2 / 2;
}

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> partitions;
    for (int i = 0; i < n; i++) {
        long long partition = prairiePartition(nums[i]);
        partitions.push_back(partition);
    }

    sort(partitions.begin(), partitions.end());

    for (int m = 1; m <= n; m++) {
        vector<long long> sequence;
        int j = 0;
        for (int i = 1; i <= m; i++) {
            long long sum = 0;
            while (j < n && partitions[j] == i) {
                sum += nums[j];
                j++;
            }
            sequence.push_back(sum);
        }

        sort(sequence.begin(), sequence.end());

        if (sequence == nums) {
            cout << m << " ";
        }
    }

    cout << endl;

    return 0;
}