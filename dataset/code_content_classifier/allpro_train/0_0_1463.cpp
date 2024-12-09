#include <iostream>
#include <map>

int main() {
    std::map<int, int> roomNumberMap = {
        {1, 1}, {2, 2}, {3, 3}, {4, 5}, {5, 7},
        {6, 8}, {7, 9}, {8, 10}, {9, 11}, {10, 12},
        {11, 13}, {12, 15}, {13, 17}, {14, 18}, {15, 19}
    };
    
    int oldRoomNumber;
    while (std::cin >> oldRoomNumber) {
        if (oldRoomNumber == 0) {
            break;
        }
        std::cout << roomNumberMap[oldRoomNumber] << std::endl;
    }

    return 0;
}