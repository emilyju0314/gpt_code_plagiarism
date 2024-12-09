#include <iostream>
#include <vector>
using namespace std;

void printActions(int n, vector<pair<int, pair<int, int>>> actions) {
    cout << actions.size() << endl;
    for(auto action : actions) {
        cout << action.first << " " << action.second.first << " " << action.second.second << endl;
    }
}

void cyclicShift(vector<int>& a, int l, int r, int d, vector<pair<int, int>>& swaps) {
    vector<int> temp;
    for(int i = l-1; i <= r-1; i++) {
        temp.push_back(a[i]);
    }
    for(int i = l-1; i <= r-1; i++) {
        a[i] = temp[(i-l+d) % temp.size()];
    }
    swaps.push_back(make_pair(l, r));
}

void sortArray(vector<int>& a) {
    int n = a.size();
    vector<pair<int, pair<int, int>>> actions;
    vector<pair<int, int>> swaps;

    for(int i = 1; i < n; i++) {
        cyclicShift(a, 1, n, i, swaps);
    }

    for(int i = n-1; i >= 1; i--) {
        cyclicShift(a, i, n, n-i, swaps);
    }

    actions.push_back(make_pair(1, make_pair(n, n)));
    printActions(n, actions);
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sortArray(a);
    }

    return 0;
}