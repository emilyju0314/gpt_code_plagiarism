#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> jars(n);
    for(int i=0; i<n; i++) {
        cin >> jars[i];
    }

    sort(jars.begin(), jars.end(), greater<int>());

    int pigletHoney = 0;
    for(int i=0; i<n; i++) {
        if(jars[i] < k || i % 3 == 2) {
            pigletHoney += jars[i];
        } else {
            pigletHoney += k;
        }
    }

    cout << pigletHoney << endl;

    return 0;
}