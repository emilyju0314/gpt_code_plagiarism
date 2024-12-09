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

    set<int> possibleX;
    possibleX.insert(0);

    set<int> prevX = {0};

    for (int i = 0; i < n; i++) {
        set<int> currX = prevX;
        for (int x : prevX) {
            currX.insert(x ^ a[i]);
        }
        prevX = currX;

        for (int x : currX) {
            possibleX.insert(x);
        }
    }

    cout << possibleX.size() << endl;
    for (int x : possibleX) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}