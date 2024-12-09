#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, A;
    cin >> n >> A;

    vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<int> countA(1000001, 0);
    vector<int> countB(1000001, 0);

    int maxB = -1;
    int maxCount = 0;

    for(int i = 0; i < n; i++) {
        if(i > 0) {
            if(colors[i] != A) {
                countB[colors[i]]++;
                if(countB[colors[i]] >= countA[colors[i]]) {
                    if(countB[colors[i]] > maxCount) {
                        maxCount = countB[colors[i]];
                        maxB = colors[i];
                    }
                }
            }
        }
        countA[colors[i]]++;
    }

    if(maxB != -1) {
        cout << maxB << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}