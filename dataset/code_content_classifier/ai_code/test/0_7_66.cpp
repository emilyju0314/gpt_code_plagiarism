#include <iostream>
using namespace std;

int last_remaining_card(int N, int A, int B, string D_A, string D_B) {
    int remaining_card = 0;
    
    if (D_A != D_B) {
        remaining_card = max(A, N - 1 - B);
    } else {
        remaining_card = A + (N - 1 - B - A) / 2;
    }
    
    return remaining_card;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N, A, B;
        string D_A, D_B;
        cin >> N >> A >> B >> D_A >> D_B;
        
        int result = last_remaining_card(N, A, B, D_A, D_B);
        cout << result << endl;
    }
    
    return 0;
}