#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        int A, B, C, D, X0, Y0;
        cin >> A >> B >> C >> D >> X0 >> Y0;

        vector<pair<int, int>> destinations;
        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            destinations.push_back(make_pair(X, Y));
        }

        int num_damage = 0;
        int current_x = X0, current_y = Y0;
        for (int i = 0; i < N; i++) {
            int dest_x = destinations[i].first;
            int dest_y = destinations[i].second;

            while (current_x != dest_x || current_y != dest_y) {
                if (current_x < dest_x) {
                    current_x++;
                } else if (current_x > dest_x) {
                    current_x--;
                }
                if (current_y < dest_y) {
                    current_y++;
                } else if (current_y > dest_y) {
                    current_y--;
                }

                if (!(A <= current_x && current_x <= C && B <= current_y && current_y <= D)) {
                    num_damage++;
                }
            }
        }

        cout << num_damage << endl;
    }

    return 0;
}