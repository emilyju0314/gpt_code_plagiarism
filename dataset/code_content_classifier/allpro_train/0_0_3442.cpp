#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> balls(N);
    unordered_map<int, int> freq;

    for (int i = 0; i < N; i++) {
        cin >> balls[i];
        freq[balls[i]]++;
    }

    int pairs = 0;

    for (int i = 0; i < N; i++) {
        int power = 1;
        while (power <= 1e9) {
            int toFind = power - balls[i];
            if (toFind == balls[i]) {
                pairs += freq[toFind] / 2;
            } else {
                pairs += min(freq[toFind], freq[balls[i]]);
            }
            power *= 2;
        }
    }

    cout << pairs << endl;

    return 0;
}