#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> A(n);
    vector<long long> B(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<int> actions;

    vector<long long> prefix_sum(n);
    prefix_sum[0] = A[0];
    for(int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + A[i];
    }

    bool possible = true;
    long long diff = B[0] - A[0];

    for(int i = 0; i < n; i++) {
        long long actual_diff = B[i] - (i > 0 ? prefix_sum[i-1] : 0);
        if(actual_diff != diff) {
            possible = false;
            break;
        }
    }

    if(!possible) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int count = 0;
    actions.push_back(0); // Initialize with 0 operations of second type

    for(int i = n-1; i > 0; i--) {
        long long change = B[i] - A[i];
        while(change >= diff) {
            count++;
            actions.push_back(i);
            change -= diff;
        }
        diff = change;
    }

    if(count > 2e5) {
        cout << "BIG" << endl;
        cout << count << endl;
    } else {
        cout << "SMALL" << endl;
        cout << count << endl;
        for(int i = actions.size() - 1; i >= 0; i--) {
            for(int j = 0; j < actions[i]; j++) {
                cout << "P";
            }
            cout << "R";
        }
    }

    return 0;
}