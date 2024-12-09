#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        
        vector<int> abilities(M);
        vector<int> positions(M);
        
        for (int i = 0; i < M-1; i++) {
            cin >> abilities[i] >> positions[i];
        }
        
        int last_ability, max_strength = 0;
        
        cin >> last_ability;
        
        for (int i = 1; i <= N; i++) {
            int min_strength = 0;
            for (int j = 0; j < M; j++) {
                min_strength += max(abilities[j] - abs(i - positions[j]), 0);
            }
        
            max_strength = max(max_strength, min_strength + max(last_ability - abs(i - positions[M-1]), 0));
        }
        
        cout << max_strength << endl;
    }
    
    return 0;
}