#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> cards(N);
    for(int i = 0; i < N; i++){
        cin >> cards[i];
    }

    int min_cards_to_eat = 0;

    // Loop through all possible subsets of cards to find minimum cards to eat
    for(int mask = 0; mask < (1 << N); mask++) {
        int sum = 0;
        int cards_eaten = 0;
        for(int i = 0; i < N; i++) {
            if(mask & (1 << i)) {
                sum += cards[i];
                cards_eaten++;
            }
        }
        if(sum == K) {
            min_cards_to_eat = N - cards_eaten;
            break;
        }
    }

    cout << min_cards_to_eat << endl;

    return 0;
}