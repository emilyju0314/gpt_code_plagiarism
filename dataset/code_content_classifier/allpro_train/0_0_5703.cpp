#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        
        vector<int> cells(N);
        vector<int> dice_rolls(M);
        
        for (int i = 0; i < N; i++) {
            cin >> cells[i];
        }
        
        for (int j = 0; j < M; j++) {
            cin >> dice_rolls[j];
        }
        
        int current_square = 0;
        int num_rolls = 0;
        
        while (current_square < N) {
            current_square += dice_rolls[num_rolls];
            current_square += cells[current_square];
            num_rolls++;
        }
        
        cout << num_rolls << endl;
    }
    
    return 0;
}