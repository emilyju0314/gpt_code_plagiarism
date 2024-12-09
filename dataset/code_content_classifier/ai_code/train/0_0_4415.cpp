#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> scores(N);
    for(int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    vector<int> dosanko_values(3);
    vector<int> dosanko_points(3);
    int dosanko_total = 0;

    for(int i = 0; i < 3; i++) {
        cin >> dosanko_values[0] >> dosanko_values[1] >> dosanko_values[2];
        dosanko_points[i] = scores[N-1];
        dosanko_total += dosanko_points[i];
    }

    int min_increase = 1000000;

    for(int i = 0; i < 3; i++) {
        int cur_value = dosanko_values[i];
        int cur_points = dosanko_points[i];
        for(int j = 1; j <= 100; j++) {
            dosanko_values[i] = cur_value + j;
            sort(dosanko_values.begin(), dosanko_values.end(), greater<int>());
            int new_total = 0;
            for(int k = 0; k < 3; k++) {
                int cur_rank = find(dosanko_values.begin(), dosanko_values.end(), cur_value) - dosanko_values.begin() + 1;
                new_total += scores[cur_rank - 1];
            }
            if(new_total >= dosanko_total && new_total < dosanko_total + 3) {
                min_increase = min(min_increase, j);
            }
        }
        dosanko_values[i] = cur_value;
    }

    if(min_increase == 1000000) {
        cout << "Saiko" << endl;
    } else {
        cout << min_increase << endl;
    }

    return 0;
}