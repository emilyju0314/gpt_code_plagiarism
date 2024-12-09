#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> tree(N, vector<int>(N, 1e9));

    for (int i = 0; i < N-1; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        tree[A-1][B-1] = C;
        tree[B-1][A-1] = C;
    }

    for (int i = 0; i < N; i++) 
        tree[i][i] = 0;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tree[i][j] = min(tree[i][j], tree[i][k] + tree[k][j]);
            }
        }
    }

    int longest_path = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            longest_path = max(longest_path, tree[i][j]);
        }
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    cout << 2 * longest_path + sum << endl;

    return 0;
}