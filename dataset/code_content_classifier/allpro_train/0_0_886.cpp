#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int S_f, P_f, G_f;
    cin >> S_f >> P_f >> G_f;

    int N;
    cin >> N;

    map<pair<int, pair<int, int>>, int> bottles;

    for (int i = 0; i < N; i++) {
        char action;
        int S, P, G;
        cin >> action >> S >> P >> G;

        pair<int, pair<int, int>> ratio = {gcd(gcd(S, P), G), {S / gcd(gcd(S, P), G), P / gcd(gcd(S, P), G)}};

        if (action == 'A') {
            bottles[ratio]++;
        } else {
            bottles[ratio]--;
            if (bottles[ratio] == 0) {
                bottles.erase(ratio);
            }
        }

        int min_bottles = 0;
        bool possible = false;
        for (auto [curr_ratio, count] : bottles) {
            if (curr_ratio.first % ratio.first == 0 && curr_ratio.second.first % ratio.second.first == 0) {
                int factor1 = curr_ratio.first / ratio.first;
                int factor2 = curr_ratio.second.first / ratio.second.first;
                if (factor1 == factor2 && factor1 * S_f == curr_ratio.second.first && factor1 * P_f == curr_ratio.second.second && factor1 * G_f == curr_ratio.second.second) {
                    min_bottles = 1;
                    possible = true;
                    break;
                }
            }
        }

        if (!possible) {
            for (auto [curr_ratio, count] : bottles) {
                if (bottles.count({curr_ratio.first * ratio.first, {curr_ratio.second.first * ratio.second.first, curr_ratio.second.second * ratio.second.second}})) {
                    min_bottles = max(min_bottles, count + bottles[{curr_ratio.first * ratio.first, {curr_ratio.second.first * ratio.second.first, curr_ratio.second.second * ratio.second.second}}]);
                    possible = true;
                }
            }
        }

        cout << (possible ? min_bottles : 0) << endl;
    }

    return 0;
}