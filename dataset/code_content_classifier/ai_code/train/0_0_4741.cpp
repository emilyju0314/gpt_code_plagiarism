#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> x(N), y(N);
    vector<char> direction(N);
    
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> direction[i];
    }

    long long xmax = -1e9, xmin = 1e9, ymax = -1e9, ymin = 1e9;

    for(int i = 0; i < N; i++) {
        if(direction[i] == 'U') {
            ymin = min(ymin, y[i]);
        } else if(direction[i] == 'D') {
            ymax = max(ymax, y[i]);
        }

        if(direction[i] == 'R') {
            xmin = min(xmin, x[i]);
        } else if(direction[i] == 'L') {
            xmax = max(xmax, x[i]);
        }
    }

    long double result = max(0LL, (long long)(xmax - xmin)) * max(0LL, (long long)(ymax - ymin));
    cout.precision(10);
    cout << fixed << result << endl;

    return 0;
}