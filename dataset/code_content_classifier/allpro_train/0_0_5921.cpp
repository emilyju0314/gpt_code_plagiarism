#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> debt(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        debt[a] -= c;
        debt[b] += c;
    }

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(debt[i] > 0) {
            sum += debt[i];
        }
    }

    cout << sum << endl;

    return 0;
}