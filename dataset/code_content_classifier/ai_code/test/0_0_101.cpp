#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        string colors;
        cin >> colors;

        vector<int> blue, red;
        for(int i=0; i<n; i++) {
            if(colors[i] == 'B') {
                blue.push_back(arr[i]);
            } else {
                red.push_back(arr[i]);
            }
        }

        sort(blue.begin(), blue.end());
        sort(red.begin(), red.end());

        bool possible = true;
        for(int i=0; i<blue.size(); i++) {
            if(blue[i] != i+1) {
                possible = false;
                break;
            }
        }
        for(int i=0; i<red.size(); i++) {
            if(red[i] != n-i) {
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}