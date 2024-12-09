#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int N, K;
        cin >> N >> K;
        
        if (N == 0 && K == 0) {
            break;
        }
        
        vector<int> fridge(K);
        vector<vector<int>> vampires(N, vector<int>(K));
        
        for (int i = 0; i < K; i++) {
            cin >> fridge[i];
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                cin >> vampires[i][j];
            }
        }
        
        bool canPrepare = true;
        for (int j = 0; j < K; j++) {
            int requiredBlood = 0;
            for (int i = 0; i < N; i++) {
                requiredBlood += vampires[i][j];
            }
            if (requiredBlood > fridge[j]) {
                canPrepare = false;
                break;
            }
        }
        
        if (canPrepare) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}