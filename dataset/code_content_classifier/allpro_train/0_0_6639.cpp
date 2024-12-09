#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> columns(n, 0);

    for(int i = 0; i < m; i++) {
        int c;
        cin >> c;
        columns[c-1]++;
    }

    int min_height = columns[0];
    for(int i = 1; i < n; i++) {
        min_height = min(min_height, columns[i]);
    }

    cout << min_height << endl;

    return 0;
}