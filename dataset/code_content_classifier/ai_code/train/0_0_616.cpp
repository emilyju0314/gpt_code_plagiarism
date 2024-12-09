#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bulbs(n);
    for(int i = 0; i < n; i++) {
        cin >> bulbs[i];
    }

    vector<int> even;
    vector<int> odd;
    for(int i = 0; i < n; i++) {
        if(bulbs[i] != 0) {
            if(bulbs[i] % 2 == 0) {
                even.push_back(bulbs[i]);
            } else {
                odd.push_back(bulbs[i]);
            }
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int minComplexity = 0;
    for(int i = 0, j = 0; i < even.size() || j < odd.size(); ) {
        if(i < even.size() && (j >= odd.size() || even[i] < odd[j])) {
            if(i % 2 == 1) {
                minComplexity++;
            }
            i++;
        } else {
            if(j % 2 == 1) {
                minComplexity++;
            }
            j++;
        }
    }

    cout << minComplexity << endl;

    return 0;
}