#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<int> output;
    
    for (int K = 1; K <= N; K++) {
        bool isWellSorted = true;
        for (int i = 0; i < K; i++) {
            if (a[i] != a[N-K+i]) {
                isWellSorted = false;
                break;
            }
        }
        if (isWellSorted) {
            output.push_back(K);
        }
    }
    
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    
    return 0;
}