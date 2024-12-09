#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to convert integer to binary string
string intToBinaryString(int num) {
    string binary = "";
    for (int i = 0; i < 30; i++) {
        if ((num & (1 << i)) != 0) {
            binary = "1" + binary;
        } else {
            binary = "0" + binary;
        }
    }
    return binary;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        vector<int> possible_k;

        for (int k = 0; k < 30; k++) {
            vector<int> eliminated(n, 0);

            for (int j = 0; j < n; j++) {
                eliminated[j] = arr[j] & ((1 << k) - 1);
            }

            sort(eliminated.begin(), eliminated.end());

            bool possible = true;
            for (int j = 1; j < n; j++) {
                if (eliminated[j] == eliminated[j-1]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                possible_k.push_back(k+1);
            }
        }

        for (int j = 0; j < possible_k.size(); j++) {
            cout << possible_k[j];
            if (j != possible_k.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}