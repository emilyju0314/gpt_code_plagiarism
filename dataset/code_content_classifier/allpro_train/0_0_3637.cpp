#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n), r(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if(dist > r[j] || dist + r[i] <= r[j]) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}