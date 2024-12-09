#include <iostream>
#include <vector>

using namespace std;

bool possibleToRemoveStones(vector<int>& A, vector<vector<int>>& tree) {
    int n = A.size();
    if (n == 2) return A[0] == A[1];
    
    int leafCount = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i].size() == 1) {
            leafCount++;
        }
    }
    
    int totalStones = 0;
    for (int stones : A) {
        totalStones += stones;
    }
    
    return totalStones % 2 == 0 && leafCount >= 2;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }
    
    bool result = possibleToRemoveStones(A, tree);
    
    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}