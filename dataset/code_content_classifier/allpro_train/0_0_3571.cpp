#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> flowers(N);
    for(int i = 0; i < N; i++) {
        cin >> flowers[i];
    }

    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        
        if(T == 1) {
            int L, R, X;
            cin >> L >> R >> X;
            for(int j = L-1; j <= R-1; j++) {
                flowers[j] = X;
            }
        } else {
            int K;
            cin >> K;
            int beautiness = 0;
            unordered_set<int> distinctTypes;
            for(int j = 0; j < K; j++) {
                distinctTypes.insert(flowers[j]);
            }
            beautiness += distinctTypes.size();
            for(int j = 1; j <= N-K; j++) {
                distinctTypes.erase(flowers[j-1]);
                distinctTypes.insert(flowers[j+K-1]);
                beautiness += distinctTypes.size();
            }
            cout << beautiness << endl;
        }
    }

    return 0;
}