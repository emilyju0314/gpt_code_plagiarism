#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, H;
    cin >> N >> H;

    vector<int> A(N), B(N), C(N), D(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // Sort the jigsaw pieces based on their height
    vector<pair<int, int>> pieces;
    for(int i = 0; i < N; i++) {
        pieces.push_back({A[i], i});
        pieces.push_back({B[i], i});
    }
    sort(pieces.begin(), pieces.end());

    // Initialize the heights and positions of the pieces
    vector<int> heights(N, H);
    vector<int> positions(N, 0);

    // Iterate through the sorted jigsaw pieces
    for(auto p : pieces) {
        int idx = p.second;
        if(p.first == A[idx]) {  // If it is the left part of the piece
            if(positions[idx] == 0) { // If the left part has not been placed yet
                positions[idx] = C[idx];
                heights[idx]--;
                continue;
            }
        } else { // If it is the right part of the piece
            if(positions[idx] == 0) { // If the right part has not been placed yet
                positions[idx] = D[idx];
                heights[idx]--;
                continue;
            }
        }

        // If the piece cannot be placed according to the conditions
        cout << "NO" << endl;
        return 0;
    }

    // If all pieces can be placed according to the conditions
    cout << "YES" << endl;
    return 0;
}