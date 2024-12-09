#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m(n);
    for(int i = 0; i < n; i++) {
        cin >> m[i];
    }

    int minBelow = 0;
    int currAbove = 0;

    for(int i = 0; i < n; i++) {
        if(currAbove < m[i]) {
            minBelow += m[i] - currAbove;
        }
        currAbove = m[i];
    }

    cout << minBelow << endl;

    return 0;
}