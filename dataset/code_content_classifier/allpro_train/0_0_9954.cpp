#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool isPossible(int num, int hits, int blows, int guess) {
    int numArr[4] = {num / 1000, (num / 100) % 10, (num / 10) % 10, num % 10};
    int guessArr[4] = {guess / 1000, (guess / 100) % 10, (guess / 10) % 10, guess % 10};

    int hitCount = 0, blowCount = 0;

    for (int i = 0; i < 4; i++) {
        if (numArr[i] == guessArr[i]) {
            hitCount++;
        } else {
            for (int j = 0; j < 4; j++) {
                if (numArr[i] == guessArr[j]) {
                    blowCount++;
                    break;
                }
            }
        }
    }

    return hitCount == hits && blowCount == blows;
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<int> possibleNumbers;
        for (int i = 0; i < N; i++) {
            int guess, hits, blows;
            std::cin >> guess >> hits >> blows;

            std::set<int> newPossibleNumbers;
            for (int num = 1000; num <= 9999; num++) {
                if (isPossible(num, hits, blows, guess)) {
                    newPossibleNumbers.insert(num);
                }
            }

            if (i == 0) {
                possibleNumbers.assign(newPossibleNumbers.begin(), newPossibleNumbers.end());
            } else {
                std::vector<int> intersection;
                std::set_intersection(possibleNumbers.begin(), possibleNumbers.end(),
                                      newPossibleNumbers.begin(), newPossibleNumbers.end(),
                                      std::back_inserter(intersection));
                possibleNumbers = intersection;
            }
        }

        if (possibleNumbers.size() == 1) {
            std::cout << possibleNumbers[0] << std::endl;
        } else {
            std::set<int> criticalNumbers;
            for (int num : possibleNumbers) {
                bool isCritical = true;
                for (int nextGuess = 1000; nextGuess <= 9999; nextGuess++) {
                    for (int i = 0; i < N; i++) {
                        int hits, blows;
                        std::cin >> hits >> blows;
                        if (!isPossible(num, hits, blows, nextGuess)) {
                            isCritical = false;
                            break;
                        }
                    }
                }
                if (isCritical) {
                    criticalNumbers.insert(num);
                }
            }

            if (!criticalNumbers.empty()) {
                std::cout << *criticalNumbers.begin() << std::endl;
            } else {
                std::cout << "????" << std::endl;
            }
        }
    }
    return 0;
}