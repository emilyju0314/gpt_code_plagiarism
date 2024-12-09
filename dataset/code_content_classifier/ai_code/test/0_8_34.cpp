#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_X = 8192;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> possible(MAX_X, false);
    possible[0] = true;
    for(int num : a) {
        vector<bool> new_possible = possible;
        for(int i = 0; i < MAX_X; i++) {
            if(possible[i]) {
                new_possible[i ^ num] = true;
            }
        }
        possible = new_possible;
    }

    set<int> result;
    for(int i = 0; i < MAX_X; i++) {
        if(possible[i]) {
            result.insert(i);
        }
    }

    cout << result.size() << endl;
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}