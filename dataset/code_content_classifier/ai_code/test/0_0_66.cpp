#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        long long N;
        int A, B;
        string D_A, D_B;
        cin >> N >> A >> B >> D_A >> D_B;

        vector<int> cards(N, 1); // Initialize all cards as 1 (not removed)

        int direction_A = (D_A == "left") ? -1 : 1;
        int direction_B = (D_B == "left") ? -1 : 1;

        int current_A = A;
        int current_B = B;

        while(current_A != current_B) {
            cards[current_A] = 0; // Mark card for removal
            cards[current_B] = 0; // Mark card for removal

            current_A = (current_A + direction_A + N) % N;
            current_B = (current_B + direction_B + N) % N;
        }

        // Find the last remaining card
        int last_card;
        for(int i = 0; i < N; i++) {
            if(cards[i] == 1) {
                last_card = i;
                break;
            }
        }

        cout << last_card << endl;
    }

    return 0;
}