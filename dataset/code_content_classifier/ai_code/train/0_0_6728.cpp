#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> x(N);
    vector<int> y(N);
    
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    int maxManhattanDist = max(abs(x[N-1] - x[0]), abs(y[N-1] - y[0]));
    
    cout << maxManhattanDist << endl;
    
    return 0;
}