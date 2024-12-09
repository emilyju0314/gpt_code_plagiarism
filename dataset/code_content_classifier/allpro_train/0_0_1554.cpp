#include <iostream>
#include <string>

bool isNaturalScore(std::string score) {
    char prevStep = ' ';
    bool leftStep = false;
    bool rightStep = false;

    for (char step : score) {
        if (step == prevStep) {
            return false;
        }

        if ((step == 'L' && leftStep) || (step == 'R' && rightStep)) {
            return false;
        }

        if (step == 'L') {
            leftStep = true;
            rightStep = false;
        } else if (step == 'R') {
            leftStep = false;
            rightStep = true;
        }

        prevStep = step;
    }

    return true;
}

int main() {
    int numDataSets;
    std::cin >> numDataSets;

    for (int i = 0; i < numDataSets; i++) {
        std::string score;
        std::cin >> score;

        if (isNaturalScore(score)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}