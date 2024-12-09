#include <iostream>
#include <string>
#include <map>

using namespace std;

class Dice {
public:
    int top, front, right, left, back, bottom;

    Dice() : top(1), front(3), right(5), left(4), back(2), bottom(6) {}

    void rollNorth() {
        int temp = top;
        top = front;
        front = bottom;
        bottom = back;
        back = temp;
    }

    void rollEast() {
        int temp = top;
        top = left;
        left = bottom;
        bottom = right;
        right = temp;
    }

    void rollSouth() {
        int temp = top;
        top = back;
        back = bottom;
        bottom = front;
        front = temp;
    }

    void rollWest() {
        int temp = top;
        top = right;
        right = bottom;
        bottom = left;
        left = temp;
    }

    void rollRight() {
        int temp = front;
        front = right;
        right = back;
        back = left;
        left = temp;
    }

    void rollLeft() {
        int temp = front;
        front = left;
        left = back;
        back = right;
        right = temp;
    }
};

int main() {
    int n;
    while(true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        Dice dice;

        int total = 0;
        for (int i = 0; i < n; i++) {
            string instruction;
            cin >> instruction;

            if (instruction == "North") {
                dice.rollNorth();
            } else if (instruction == "East") {
                dice.rollEast();
            } else if (instruction == "South") {
                dice.rollSouth();
            } else if (instruction == "West") {
                dice.rollWest();
            } else if (instruction == "Right") {
                dice.rollRight();
            } else if (instruction == "Left") {
                dice.rollLeft();
            }

            total += dice.top;
        }

        cout << total << endl;
    }

    return 0;
}