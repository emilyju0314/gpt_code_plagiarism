#include <iostream>
#include <string>

std::string getFizzBuzzString(long long s) {
    std::string fizzBuzzString = "";
    long long index = 0;

    for (int i = 1; i <= 200; i++) {
        std::string str = "";
        if (i % 3 == 0 && i % 5 == 0) {
            str = "FizzBuzz";
        } else if (i % 3 == 0) {
            str = "Fizz";
        } else if (i % 5 == 0) {
            str = "Buzz";
        } else {
            str = std::to_string(i);
        }

        fizzBuzzString += str;
    }

    if (s <= fizzBuzzString.size()) {
        return fizzBuzzString.substr(s - 1, 20);
    } else {
        return "";
    }
}

int main() {
    long long s;
    std::cin >> s;

    std::string result = getFizzBuzzString(s);
    std::cout << result << std::endl;

    return 0;
}