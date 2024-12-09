#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> questions;
    questions.push_back(2);

    for (int i = 4; i < n; i += 2) {
        questions.push_back(i);
    }

    std::cout << questions.size() << std::endl;
    for (int question : questions) {
        std::cout << question << " ";
    }

    return 0;
}