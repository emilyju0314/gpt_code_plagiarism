#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    double P;
    cin >> N >> P;

    // Calculate the probability of not playing a studied map
    double probability_not_playing = 1.0;
    for(int i = 0; i < N - 1; i++) {
        probability_not_playing *= (double)(N - i - 1) / N;
    }

    // Increment the number of studied maps until the probability of playing a studied map is at least P
    int num_studied_maps = 0;
    while (1 - probability_not_playing < P) {
        num_studied_maps++;
        probability_not_playing *= (double)(N - num_studied_maps) / N;
    }

    cout << num_studied_maps << endl;

    return 0;
}