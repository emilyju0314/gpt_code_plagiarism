#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    
    vector<int> balls(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i];
    }
    
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        
        bool chance = false;
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k < (1 << N); k++) {
                int sum = 0;
                for (int l = 0; l < N; l++) {
                    if ((k >> l) & 1) {
                        sum += balls[l];
                    }
                }
                if (sum % T >= A && sum / T >= B) {
                    chance = true;
                    break;
                }
            }
            if (chance) {
                break;
            }
        }
        
        if (chance) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}