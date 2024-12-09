#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> marked(n);
    for(int i = 0; i < n; i++) {
        cin >> marked[i];
    }

    // Construct a vector to store the positions of marked cells in each row
    vector<vector<int>> marked_position(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        marked_position[marked[i] - 1][i] = 1;
    }

    // Calculate the number of beautiful rectangles that touch each row
    vector<int> beautiful_row(n);
    for(int i = 1; i < n - 1; i++) {
        for(int j = i - 1; j >= 0; j--) {
            beautiful_row[i] += marked_position[j][i];
        }
    }

    // Answer each query rectangle
    for(int i = 0; i < q; i++) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        
        int answer = 0;
        for(int j = l - 1; j <= r - 1; j++) {
            answer += beautiful_row[u - 1] - beautiful_row[d - 2];
        }
        
        cout << answer << endl;
    }

    return 0;
}