#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int max_distance = 0;
    // Calculate the maximum distance for each possible t
    for (char first_char : {'B', 'N'}) {
        for (char second_char : {'B', 'N'}) {
            string t = {first_char, second_char};
            int current_max_distance = 0;
            for (string str : s) {
                int distance = 0;
                for (char c : str) {
                    if (c != t[distance % 2]) {
                        distance++;
                    }
                }
                current_max_distance = max(current_max_distance, distance);
            }
            max_distance = max(max_distance, current_max_distance);
        }
    }

    cout << max_distance << endl;
    cout << "BN" << endl;

    return 0;
}