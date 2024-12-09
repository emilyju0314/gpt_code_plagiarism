#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;

    if (s < k || s > (n - 1) * k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int current_house = 1;
        vector<int> moves;
        for (int i = 0; i < k; i++) {
            if (current_house + s - (k - i - 1) <= n) {
                current_house += s - (k - i - 1);
                s = k - i - 1;
                moves.push_back(current_house);
            } else {
                current_house = n - (s - (k - i - 1 - n + current_house));
                s = k - i - 1;
                moves.push_back(current_house);
            }
        }
        for (int move : moves) {
            cout << move << " ";
        }
        cout << endl;
    }

    return 0;
}