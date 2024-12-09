#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> passwords(n);
    string correct_password;

    for (int i = 0; i < n; i++) {
        cin >> passwords[i];
    }
    cin >> correct_password;

    int best_case = 1;
    int worst_case = 1;
    int correct_password_length = correct_password.length();

    for (int i = 0; i < n; i++) {
        if (passwords[i].length() < correct_password_length) {
            best_case++;
            worst_case++;
        } else if (passwords[i].length() == correct_password_length) {
            worst_case++;
        }
    }

    worst_case += (worst_case - 1) / k * 5;

    cout << best_case << " " << worst_case << endl;

    return 0;
}