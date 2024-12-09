#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<pair<int, int>, pair<int, int>>> queries;

    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries.push_back({{a, b}, {c, d}});
    }

    int maxScore = 0;

    vector<int> A(N, 1);

    do {
        int score = 0;
        for (auto query : queries) {
            int a = query.first.first - 1;
            int b = query.first.second - 1;
            int c = query.second.first;
            int d = query.second.second;

            if (A[b] - A[a] == c) {
                score += d;
            }
        }
        maxScore = max(maxScore, score);
    } while (next_permutation(A.begin(), A.end()));

    cout << maxScore << endl;

    return 0;
}