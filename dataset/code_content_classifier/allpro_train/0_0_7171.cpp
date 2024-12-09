#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int rock_count = 0, paper_count = 0;
    int score = 0;

    for(char c : s) {
        if(c == 'g') {
            rock_count++;
            if(paper_count > 0) {
                paper_count--;
                score++;
            }
        } else {
            paper_count++;
        }
    }

    std::cout << score << std::endl;

    return 0;
}