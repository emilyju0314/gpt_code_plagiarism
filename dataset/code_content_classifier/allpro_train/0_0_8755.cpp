#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    unordered_set<long long> uniqueA(a.begin(), a.end());
    vector<vector<int>> groups;

    for(int i = 0; i < n; i++) {
        bool newGroup = true;
        for(auto& group : groups) {
            bool canWorkTogether = true;
            for(int j : group) {
                if((a[i] & a[j]) != 0) {
                    canWorkTogether = false;
                    break;
                }
            }
            if(canWorkTogether) {
                group.push_back(i);
                newGroup = false;
                break;
            }
        }
        if(newGroup) {
            groups.push_back({i});
        }
    }

    long long maxSum = 0;
    for(auto& group : groups) {
        if(group.size() >= 2) {
            long long sum = 0;
            for(int i : group) {
                sum += b[i];
            }
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << endl;

    return 0;
}