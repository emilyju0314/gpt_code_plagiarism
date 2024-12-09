#include <iostream>
#include <vector>
#include <algorithm>

bool isValidGuess(std::string guess, std::string actual, int bulls, int cows) {
    int bullCount = 0;
    int cowCount = 0;

    for (int i = 0; i < 4; i++) {
        if (guess[i] == actual[i]) {
            bullCount++;
        } else if (actual.find(guess[i]) != std::string::npos) {
            cowCount++;
        }
    }

    return bullCount == bulls && cowCount == cows;
}

bool isValidNumber(std::string number) {
    if (number.size() != 4) {
        return false;
    }
    std::sort(number.begin(), number.end());
    return std::adjacent_find(number.begin(), number.end()) == number.end();
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> guesses(n);
    std::vector<int> bulls(n);
    std::vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        std::cin >> guesses[i] >> bulls[i] >> cows[i];
    }

    for (int i = 0; i <= 9999; i++) {
        std::string guess = std::to_string(i);
        while (guess.length() < 4) {
            guess = '0' + guess;
        }

        if (!isValidNumber(guess)) {
            continue;
        }

        bool valid = true;
        for (int j = 0; j < n; j++) {
            if (!isValidGuess(guess, guesses[j], bulls[j], cows[j])) {
                valid = false;
                break;
            }
        }

        if (valid) {
            std::cout << guess << std::endl;
            return 0;
        }
    }

    std::cout << "Need more data" << std::endl;

    return 0;
}