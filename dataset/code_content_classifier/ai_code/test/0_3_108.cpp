#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> strengthsA(n);
        vector<int> strengthsB(n);

        for(int i = 0; i < n; i++) {
            cin >> strengthsA[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> strengthsB[i];
        }

        int minStrengthB = *min_element(strengthsB.begin(), strengthsB.end());
        int maxStrengthA = *max_element(strengthsA.begin(), strengthsA.end());

        for(int i = 0; i < n; i++) {
            if(strengthsA[i] > maxStrengthA && strengthsB[i] > minStrengthB) {
                cout << "0";
            } else {
                cout << "1";
            }
        }

        cout << endl;
    }

    return 0;
}