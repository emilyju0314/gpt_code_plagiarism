#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    vector<int> leaves(N);
    for(int i = 0; i < N; i++) {
        cin >> leaves[i];
    }

    int discarded = 0;
    vector<int> discard_candidates;
    for(int i = 0; i < N; i++) {
        if (leaves[i] >= A) {
            discard_candidates.push_back(i);
            if (discard_candidates.size() > M) {
                break;
            }
        }
    }

    for(int i = discard_candidates.size() - 1; i >= 0; i--) {
        if (leaves[discard_candidates[i]] < B) {
            discard_candidates.pop_back();
        }
    }

    cout << discard_candidates.size() << endl;

    return 0;
}