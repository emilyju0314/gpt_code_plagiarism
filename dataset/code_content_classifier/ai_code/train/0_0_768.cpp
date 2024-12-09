#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> combat_power(N, 0);

    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;

        if (query == "IN") {
            int A, B, C;
            cin >> A >> B >> C;
            A--; B--;
            combat_power[A] += C;
            combat_power[B] += C;
        } else if (query == "COMPARE") {
            int A, B;
            cin >> A >> B;
            A--; B--;
            if (combat_power[A] < combat_power[B]) {
                cout << combat_power[B] - combat_power[A] << endl;
            } else {
                cout << "WARNING" << endl;
            }
        }
    }

    return 0;
}