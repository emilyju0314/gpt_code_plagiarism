#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m(n);
    for(int i=0; i<n; i++) {
        cin >> m[i];
    }

    int maxAbove = 0;
    int sumBelow = 0;
    for(int i=0; i<n; i++) {
        maxAbove = max(maxAbove, m[i]);
        sumBelow += maxAbove - m[i];
    }

    cout << sumBelow << endl;

    return 0;
}