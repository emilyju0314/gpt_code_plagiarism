#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    // Try to sort the permutation in ascending order
    int idx = 0;
    for(int i = 1; i < N; i++) {
        if(P[i] != P[i - 1] + 1) {
            idx = i;
            break;
        }
    }
    
    if(idx == 0) {
        cout << "Yes" << endl;
    } else {
        // Check if cyclic right shift can make it monotonic
        bool possible = false;
        for(int x = 0; x <= N - K; x++) {
            vector<int> temp(N);
            for(int i = 0; i < N; i++) {
                temp[(i + x) % N] = P[i];
            }
            
            int cnt = 0;
            for(int i = 1; i < N; i++) {
                if(temp[i] == temp[i - 1] + 1) {
                    cnt++;
                }
            }
            
            if(cnt + 1 == N) {
                possible = true;
                break;
            }
        }
        
        if(possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}