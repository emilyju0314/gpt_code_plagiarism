#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void union_set(vector<int>& parent, int x, int y) {
    int root_x = find(parent, x);
    int root_y = find(parent, y);
    parent[root_x] = root_y;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int>> clues;
    for (int i = 0; i < Q; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        clues.push_back({A, B});
    }

    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (auto clue : clues) {
        int A = clue.first;
        int B = clue.second;
        if (A > B) swap(A, B);

        if (find(parent, A) != find(parent, B)) {
            union_set(parent, A, B);
        }
    }

    bool possible = true;
    for (auto clue : clues) {
        int A = clue.first;
        int B = clue.second;
        if (A > B) swap(A, B);

        if (find(parent, A) != find(parent, B) && parent[A] != parent[B]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}