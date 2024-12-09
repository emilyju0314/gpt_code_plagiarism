#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> row1(n);
    vector<int> row2(n);

    for(int i = 0; i < n; i++) {
        cin >> row1[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> row2[i];
    }

    sort(row1.begin(), row1.end());
    sort(row2.begin(), row2.end(), greater<int>());

    for(int i = 0; i < n; i++) {
        cout << row1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << row2[i] << " ";
    }
    cout << endl;

    return 0;
}