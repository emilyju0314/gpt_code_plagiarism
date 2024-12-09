#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    int num_values = pow(2, n);
    vector<int> f(num_values);
    for (int i = 0; i < num_values; i++) {
        cin >> f[i];
    }

    double game_value = 0;
    for (int i = 0; i < num_values; i++) {
        game_value += f[i];
    }
    game_value /= num_values;

    cout << fixed;
    cout.precision(6);
    cout << game_value << endl;

    for (int i = 0; i < r; i++) {
        int z, g;
        cin >> z >> g;

        game_value += (g - f[z]) / double(num_values);
        f[z] = g;

        cout << game_value << endl;
    }

    return 0;
}