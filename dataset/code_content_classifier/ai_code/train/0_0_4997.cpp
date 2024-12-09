#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, V, P;
    cin >> N >> M >> V >> P;

    vector<int> scores(N);
    for(int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end(), greater<int>());

    int threshold = scores[P-1];
    int num_candidates = 0;
    for(int i = 0; i < N; i++) {
        if(scores[i] >= threshold && (i < P || scores[i] + M >= scores[P-1])) {
            num_candidates++;
        }
    }

    cout << num_candidates << endl;

    return 0;
}