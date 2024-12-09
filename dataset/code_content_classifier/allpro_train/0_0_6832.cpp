#include <iostream>
#include <string>

using namespace std;

int main() {
    int num_datasets;
    cin >> num_datasets;

    for (int i = 0; i < num_datasets; i++) {
        int N;
        string team_order;
        cin >> N >> team_order;

        int num_B = 0;
        int num_G = 0;
        int num_rounds = team_order.length();

        for (int j = 0; j < num_rounds; j++) {
            if (team_order[j] == 'B') {
                num_B++;
            } else {
                num_G++;
            }
        }

        int remaining_B = 0;
        for (int j = 0; j < num_rounds; j++) {
            if (team_order[j] == 'B') {
                if ((num_B - 1) * N >= num_rounds - 1 || (num_B - 1) * (N - 1) + j - remaining_B >= num_rounds - 1) {
                    remaining_B++;
                } else {
                    break;
                }
            } else {
                if ((num_B) * N >= num_rounds - 1 || (num_B) * (N - 1) + j - remaining_B >= num_rounds - 1) {
                    continue;
                } else {
                    break;
                }
            }
        }

        cout << remaining_B << endl;
    }

    return 0;
}