#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int taroScore = 0;
    int hanakoScore = 0;

    for (int i = 0; i < n; i++) {
        std::string taroCard, hanakoCard;
        std::cin >> taroCard >> hanakoCard;

        if (taroCard == hanakoCard) {
            taroScore++;
            hanakoScore++;
        } else if (taroCard < hanakoCard) {
            hanakoScore += 3;
        } else {
            taroScore += 3;
        }
    }

    std::cout << taroScore << " " << hanakoScore << std::endl;

    return 0;
}