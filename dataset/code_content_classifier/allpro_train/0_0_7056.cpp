#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ranks(n);
    for (int i = 0; i < n; i++) {
        cin >> ranks[i];
    }

    sort(ranks.begin(), ranks.end());
    
    double expectedRank = 0.0;
    for (int i = 0; i < n; i++) {
        expectedRank += ranks[i] * (1.0/(m-1));
    }
    
    cout << fixed << setprecision(10) << expectedRank << endl;

    return 0;
}