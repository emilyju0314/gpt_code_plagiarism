#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> possible_values;
    possible_values.insert(0);

    for(int i = 0; i < n; i++) {
        unordered_set<int> new_values;
        for(auto val : possible_values) {
            new_values.insert(val ^ a[i]);
        }
        possible_values.insert(new_values.begin(), new_values.end());
    }

    cout << possible_values.size() - 1 << endl;
    for(auto it = possible_values.begin(); it != possible_values.end(); it++) {
        if(*it != 0) {
            cout << *it << " ";
        }
    }
    
    return 0;
}