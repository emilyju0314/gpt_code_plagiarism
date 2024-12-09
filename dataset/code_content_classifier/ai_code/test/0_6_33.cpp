#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> xorValues;
    xorValues.insert(0); // XOR of empty subsequence

    set<int> newValues;
    for (int i = 0; i < n; i++) {
        for (int val : xorValues) {
            newValues.insert(val ^ a[i]);
        }
        xorValues.insert(newValues.begin(), newValues.end());
        newValues.clear();
    }

    cout << xorValues.size() << endl;
    for (int val : xorValues) {
        cout << val << " ";
    }
    
    return 0;
}