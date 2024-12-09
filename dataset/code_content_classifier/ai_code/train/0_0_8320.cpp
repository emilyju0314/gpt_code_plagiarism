#include <iostream>
#include <string>

bool isPalindrome(std::string time) {
    return time[0] == time[4] && time[1] == time[3];
}

std::string nextPalindromeTime(std::string currentTime) {
    int h = std::stoi(currentTime.substr(0, 2));
    int m = std::stoi(currentTime.substr(3, 2));

    while (true) {
        m++;
        if (m == 60) {
            m = 0;
            h = (h + 1) % 24;
        }
        
        if (h < 10 && m < 10) {
            currentTime = "0" + std::to_string(h) + ":0" + std::to_string(m);
        } else if (h < 10) {
            currentTime = "0" + std::to_string(h) + ":" + std::to_string(m);
        } else if (m < 10) {
            currentTime = std::to_string(h) + ":0" + std::to_string(m);
        } else {
            currentTime = std::to_string(h) + ":" + std::to_string(m);
        }

        if (isPalindrome(currentTime)) {
            return currentTime;
        }
    }
}

int main() {
    std::string inputTime;
    std::cin >> inputTime;

    std::string result = nextPalindromeTime(inputTime);
    std::cout << result << std::endl;

    return 0;
}