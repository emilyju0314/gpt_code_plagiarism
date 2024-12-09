#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<bool> visited(n+1, false);
    vector<int> possible_positions;

    while(!visited[x]) {
        visited[x] = true;
        possible_positions.push_back(x);
        x = a[x];
    }

    for(int pos : possible_positions) {
        cout << pos << endl;
    }

    return 0;
}