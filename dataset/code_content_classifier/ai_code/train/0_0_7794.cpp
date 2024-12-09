#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> dice(6);
    string commands;

    // Read the integers assigned to each face
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    // Read the sequence of commands
    cin >> commands;

    // Initial state of the dice
    int top = dice[0], front = dice[1], right = dice[2];

    // Iterate through the commands
    for (char c : commands) {
        switch (c) {
            case 'E':
                int temp = top;
                top = 7 - right;
                right = temp;
                break;
            case 'W':
                temp = top;
                top = right;
                right = 7 - temp;
                break;
            case 'N':
                temp = top;
                top = 7 - front;
                front = temp;
                break;
            case 'S':
                temp = top;
                top = front;
                front = 7 - temp;
                break;
        }
    }

    // Print the integer on the top face after the simulation
    cout << top << endl;

    return 0;
}