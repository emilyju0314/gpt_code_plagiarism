#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<long long> prairiePartition(long long x) {
    vector<long long> partitions;
    long long current = 1;
    while (x > 0) {
        partitions.push_back(current);
        x -= current;
        current *= 2;
    }
    return partitions;
}

int main() {
    int n;
    cin >> n;

    set<long long> values;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        vector<long long> partitions = prairiePartition(num);
        for (int j = 0; j < partitions.size(); j++) {
            values.insert(partitions[j]);
        }
    }

    vector<long long> result;
    for (long long val : values) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (val < i+1) {
                valid = false;
                break;
            }
        }
        if (valid) {
            result.push_back(val);
        }
    }

    if (result.size() == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}