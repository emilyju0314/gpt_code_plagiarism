#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool canWorkTogether(int a, int b) {
    return (a | b) == b; // Check if all bits in b are set in a
}

int main() {
    int n;
    cin >> n;

    vector<long long> a(n); // array to store a_i
    vector<long long> b(n); // array to store b_i

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long maxSum = 0;

    for(int mask = 1; mask < (1 << n); mask++) {
        vector<int> group;
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                group.push_back(i);
                sum += b[i];
            }
        }

        bool canWork = true;

        for(int i = 0; i < group.size(); i++) {
            for(int j = i+1; j < group.size(); j++) {
                if(!canWorkTogether(a[group[i]], a[group[j]])) {
                    canWork = false;
                    break;
                }
            }
            if(!canWork) {
                break;
            }
        }

        if(canWork && group.size() >= 2) {
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << endl;

    return 0;
}