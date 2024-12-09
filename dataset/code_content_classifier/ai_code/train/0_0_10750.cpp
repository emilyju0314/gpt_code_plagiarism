#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> Q;
    vector<pair<int, int>> queries(Q);
    for(int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    unordered_map<int, int> counter;
    for(int i = 0; i < N; i++) {
        int current = i;
        for(int j = 0; j < 60; j++) {
            counter[current]++;
            if(counter[current] >= Q) {
                break;
            }
            current = A[current];
        }
    }

    for(auto query : queries) {
        int m = query.first;
        int y = query.second;

        int count = 0;
        int current = y;
        for(int i = 0; i < 60 && m > 0; i++) {
            if(m % 2 == 1) {
                count += counter[current];
            }
            current = A[current];
            m /= 2;
        }
        cout << count << endl;
    }

    return 0;
}