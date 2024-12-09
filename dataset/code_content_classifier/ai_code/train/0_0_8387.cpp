#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> A(N, M);
    unordered_map<int, int> count;
    
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        A[a-1]--;
        count[a]++;
    }

    int min_count = N;
    for (auto& it : count) {
        min_count = min(min_count, it.second);
    }

    if (min_count == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}