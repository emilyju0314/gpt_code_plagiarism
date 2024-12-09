#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int winner = 1;
    int max_fish = 0;

    for (int i = 0; i < n; i++) {
        int participant, fish;
        cin >> participant >> fish;

        if (fish > max_fish) {
            winner = participant;
            max_fish = fish;
        }
    }

    cout << winner << " " << max_fish << endl;

    return 0;
}