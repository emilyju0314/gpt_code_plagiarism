#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;

    string result = "";

    int current_cost = 0;
    int current_length = 1;

    while (current_cost < k) {
        int remaining_cost = k - current_cost;

        // Calculate the maximum possible length for the remaining cost
        int max_length = min(remaining_cost, current_length);

        // Append 'a' to 'z' characters based on the remaining cost and length
        for (int i = 0; i < max_length; i++) {
            result += (char)('a' + i);
        }

        current_cost += current_length;
        current_length++;
    }

    cout << result << endl;

    return 0;
}