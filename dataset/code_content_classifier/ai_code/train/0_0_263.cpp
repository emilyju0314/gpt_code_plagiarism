#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int Q;
    cin >> Q;
    
    map<pair<int, int>, int> frequencies;
    
    for (int i = 0; i < N; i++) {
        frequencies[{i, 1}] = A[i];
    }
    for (int m = 2; m <= 60; m++) { // using 60 as an upper bound for the given constraints
        for (int i = 0; i < N; i++) {
            frequencies[{i, m}] = frequencies[{frequencies[{i, m-1}], 1}];
        }
    }
    
    for (int q = 0; q < Q; q++) {
        int m, y;
        cin >> m >> y;
        
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (frequencies[{i, m}] == y) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}