#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> P(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> O(N);

    vector<pair<int, int>> sortedA;
    for (int i = 0; i < N; i++) {
        sortedA.push_back({A[i], i});
    }

    sort(sortedA.begin(), sortedA.end());

    for (int i = 0; i < N; i++) {
        int currA = A[sortedA[i].second];
        int currP = P[sortedA[i].second];

        O[sortedA[i].second] = currA ^ currP;
        
        currP = O[sortedA[i].second] ^ currP;

        for (int j = i + 1; j < N; j++) {
            int nextP = P[sortedA[j].second];
            if ((nextP ^ currP) < A[sortedA[j].second]) {
                A[sortedA[j].second] = nextP ^ currP;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << O[i] << " ";
    }

    return 0;
}