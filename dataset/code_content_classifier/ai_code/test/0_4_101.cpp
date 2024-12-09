#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isPermutationPossible(int n, vector<int>& arr, string colors) {
    vector<int> blue, red;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        if (colors[i] == 'B') {
            blue.push_back(arr[i]);
        } else {
            red.push_back(arr[i]);
        }
        freq[arr[i]]++;
    }

    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());

    for (int i = 0; i < n; i++) {
        if (freq[i+1] == 0) {
            if (!blue.empty() && blue.back() == i+1) {
                blue.pop_back();
            } else if (!red.empty() && red.back() == i+1) {
                red.pop_back();
            } else {
                return false;
            }
        }
    }

    return true;
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

        string colors;
        cin >> colors;

        if (isPermutationPossible(n, arr, colors)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}