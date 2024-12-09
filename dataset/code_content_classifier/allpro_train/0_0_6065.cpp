#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> face_values(n);
    for(int i = 0; i < n; i++) {
        cin >> face_values[i];
    }

    int smallest_non_optimal_sum = -1;

    for(int i = 1; i <= 1000; i++) {
        int sum = i;
        int optimal_coins = 0;
        for(int j = 0; j < n; j++) {
            optimal_coins += sum / face_values[j];
            sum %= face_values[j];
        }

        sum = i;
        int greedy_coins = 0;
        for(int j = 0; j < n; j++) {
            greedy_coins += sum / face_values[j];
            sum %= face_values[j];
            if(greedy_coins > optimal_coins) {
                if(smallest_non_optimal_sum == -1) {
                    smallest_non_optimal_sum = i;
                } else {
                    smallest_non_optimal_sum = min(smallest_non_optimal_sum, i);
                }
                break;
            }
        }
    }

    cout << smallest_non_optimal_sum << endl;

    return 0;
}