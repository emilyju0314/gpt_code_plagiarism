#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& str) {
    std::string rev = str;
    std::reverse(rev.begin(), rev.end());
    return str == rev;
}

int minutes_to_palindrome(const std::string& time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));

    while (true) {
        ++mm;
        if (mm == 60) {
            mm = 0;
            ++hh;
        }
        if (hh == 24) {
            hh = 0;
        }
        
        // Convert hh and mm to strings and add leading zeros if necessary
        std::string hh_str = hh < 10 ? "0" + std::to_string(hh) : std::to_string(hh);
        std::string mm_str = mm < 10 ? "0" + std::to_string(mm) : std::to_string(mm);

        // Check if the current time is a palindrome
        if (is_palindrome(hh_str + ":" + mm_str)) {
            int total_minutes = (hh - stoi(time.substr(0, 2))) * 60 + mm - stoi(time.substr(3, 2));
            return total_minutes < 0 ? total_minutes + 1440 : total_minutes; // Calculate the minimum sleep time
        }
    }
}

int main() {
    std::string time;
    std::cin >> time;

    int result = minutes_to_palindrome(time);
    std::cout << result << std::endl;

    return 0;
}