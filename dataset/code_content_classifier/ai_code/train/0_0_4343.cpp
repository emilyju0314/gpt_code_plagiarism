#include <iostream>
#include <string>

int main() {
    int n;
    std::string events;
    
    std::cin >> n;
    std::cin >> events;

    int left = 0;
    int right = 9;
    std::string roomStatus = "0000000000";

    for (int i = 0; i < n; i++) {
        char event = events[i];

        if (event == 'L') {
            while (roomStatus[left] != '0') {
                left++;
            }
            roomStatus[left] = '1';
        } else if (event == 'R') {
            while (roomStatus[right] != '0') {
                right--;
            }
            roomStatus[right] = '1';
        } else {
            int room = event - '0';
            roomStatus[room] = '0';
        }
    }

    std::cout << roomStatus << std::endl;

    return 0;
}