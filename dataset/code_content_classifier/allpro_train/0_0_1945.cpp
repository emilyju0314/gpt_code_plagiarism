#include <iostream>
#include <string>

int main() {
    std::string fyodor, matroskin, sharic;
    std::cin >> fyodor >> matroskin >> sharic;

    if ((fyodor == "rock" && matroskin == "scissors" && sharic == "scissors") ||
        (fyodor == "paper" && matroskin == "rock" && sharic == "rock") ||
        (fyodor == "scissors" && matroskin == "paper" && sharic == "rock")) {
        std::cout << "F" << std::endl;
    } else if ((matroskin == "rock" && fyodor == "scissors" && sharic == "scissors") ||
               (matroskin == "paper" && fyodor == "rock" && sharic == "rock") ||
               (matroskin == "scissors" && fyodor == "paper" && sharic == "rock")) {
        std::cout << "M" << std::endl;
    } else if ((sharic == "rock" && fyodor == "scissors" && matroskin == "scissors") ||
               (sharic == "paper" && fyodor == "rock" && matroskin == "rock") ||
               (sharic == "scissors" && fyodor == "paper" && matroskin == "rock")) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "?" << std::endl;
    }

    return 0;
}