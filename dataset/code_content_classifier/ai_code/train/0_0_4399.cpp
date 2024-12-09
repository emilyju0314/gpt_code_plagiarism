#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> b(N);
    for(int i=0; i<N; i++) {
        cin >> b[i];
    }

    int Q;
    cin >> Q;

    vector<pair<int, int>> operations(Q);
    for(int i=0; i<Q; i++) {
        cin >> operations[i].first >> operations[i].second;
    }

    int initial_hamming_distance = 0;
    for(int i=0; i<N; i++) {
        if(b[i] != 0) {
            initial_hamming_distance++;
        }
    }

    int min_hamming_distance = initial_hamming_distance;
    for(int i=0; i<Q; i++) {
        int left = operations[i].first - 1;
        int right = operations[i].second - 1;

        int num_ones = 0;
        for(int j=left; j<=right; j++) {
            if(b[j] == 1) {
                num_ones++;
            }
        }

        min_hamming_distance = min(min_hamming_distance, initial_hamming_distance - num_ones + (right - left + 1 - num_ones));
    }

    cout << min_hamming_distance << endl;

    return 0;
}