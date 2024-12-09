#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N * K; i++) {
        int index = i % N;
        
        if (s.count(A[index])) {
            while (*s.rbegin() != A[index]) {
                int elem = *s.rbegin();
                s.erase(elem);
            }
            s.erase(A[index]);
        } else {
            s.insert(A[index]);
            result.push_back(A[index]);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}