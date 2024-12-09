#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M;
    
    vector<int> blowers(M);
    for (int i = 0; i < M; i++) {
        cin >> blowers[i];
    }
    
    cin >> Q;
    
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }
    
    for (int i = 0; i < Q; i++) {
        int l = queries[i];
        int left = 1, right = N;
        int ans = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            int losses = 0;
            
            for (int j = 0; j < M; j++) {
                if (abs(blowers[j] - mid) <= (mid - 1)) {
                    losses++;
                }
            }
            
            if (losses <= l) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}