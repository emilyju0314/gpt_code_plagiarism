#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n), h(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for(int j = 0; j < m; j++) {
        int a, b;
        cin >> a >> b;
        
        a--; b--;

        int max_energy = 0;
        for(int i = a; i <= b; i++) {
            int energy = 2 * (h[a] + h[i]) + d[i];
            max_energy = max(max_energy, energy);
        }

        cout << max_energy << endl;
    }

    return 0;
}