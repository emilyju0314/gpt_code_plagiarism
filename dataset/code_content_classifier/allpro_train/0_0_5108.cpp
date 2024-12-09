#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSubsets(int n, vector<int>& T) {
    int k = T.size();

    for(int i = 0; i < (1 << n); i++) {
        bool includeT = true;

        for(int j = 0; j < k; j++) {
            if((i & (1 << T[j])) == 0) {
                includeT = false;
                break;
            }
        }

        if(includeT) {
            vector<int> subset;

            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    subset.push_back(j);
                }
            }

            cout << i << ": ";
            for(int j = 0; j < subset.size(); j++) {
                cout << subset[j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> T(k);
    for(int i = 0; i < k; i++) {
        cin >> T[i];
    }

    sort(T.begin(), T.end());

    printSubsets(n, T);

    return 0;
}