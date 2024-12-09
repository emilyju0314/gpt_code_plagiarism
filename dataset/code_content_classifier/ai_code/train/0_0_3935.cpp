#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkTree(vector<int> c) {
    sort(c.begin(), c.end());

    int n = c.size();
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += c[i];
    }

    if(sum >= c[n - 1]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    if(checkTree(c)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}