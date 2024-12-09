#include <iostream>
#include <string>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::string controller_move;
    std::cin >> controller_move;

    std::string train_state;
    std::cin >> train_state;

    int controller_pos = k;
    int stowaway_pos = m;

    bool train_moving = false;

    for (int i = 0; i < train_state.length(); i++) {
        if (train_state[i] == '0') {
            train_moving = true;
        } else {
            train_moving = false;
        }

        // Stowaway moves first if train is moving
        if (train_moving) {
            if (stowaway_pos < n) {
                stowaway_pos++;
            }
        }

        // Controller moves
        if (controller_move == "to head") {
            if (controller_pos > 1) {
                controller_pos--;
            } else {
                controller_move = "to tail";
            }
        } else {
            if (controller_pos < n) {
                controller_pos++;
            } else {
                controller_move = "to head";
            }
        }

        // Stowaway moves after controller if train is idle
        if (!train_moving) {
            if (stowaway_pos == controller_pos) {
                std::cout << "Controller " << i+1;
                return 0;
            }
            // Stowaway leaves and re-enters train at a random position
            stowaway_pos = 1 + (stowaway_pos % n);
        }
    }

    std::cout << "Stowaway";

    return 0;
}