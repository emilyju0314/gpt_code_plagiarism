#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> crossword(n);
    for (int i = 0; i < n; i++) {
        std::cin >> crossword[i];
    }

    std::vector<std::vector<int>> rows(n, std::vector<int>(26, 0));
    std::vector<std::vector<int>> cols(m, std::vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rows[i][crossword[i][j] - 'a']++;
            cols[j][crossword[i][j] - 'a']++;
        }
    }

    std::string result = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rows[i][crossword[i][j] - 'a'] == 1 && cols[j][crossword[i][j] - 'a'] == 1) {
                result += crossword[i][j];
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}