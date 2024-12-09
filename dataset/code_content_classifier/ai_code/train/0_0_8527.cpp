#include <iostream>

using namespace std;

int main() {
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    int total_length = v1; // Initialize total length with the speed at the beginning of the segment
    int prev_speed = v1; // Initialize the previous speed with the speed at the beginning of the segment

    for(int i = 2; i <= t; i++) {
        int current_speed = min(v2, prev_speed + d); // Calculate the speed for the current second
        total_length += current_speed; // Add the current speed to the total length
        prev_speed = current_speed; // Update the previous speed
    }

    cout << total_length << endl;

    return 0;
}