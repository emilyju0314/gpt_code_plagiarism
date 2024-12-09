#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> notes(n - k + 1);
    for (int i = 0; i < n - k + 1; i++) {
        std::cin >> notes[i];
    }

    std::vector<std::string> names(n);
    for (int i = 0; i < n; i++) {
        names[i] = "A";
    }

    int index = 0;
    for (int i = 0; i < n - k + 1; i++) {
        if (notes[i] == "NO") {
            names[index + k - 1] = names[index];
        }
        index++;
    }

    char c = 'B';
    for (int i = 1; i < n; i++) {
        if (names[i] == "A") {
            names[i] = c++;
            if (c == 'Z' + 1) {
                c = 'a';
            } else if (c == 'z' + 1) {
                c = 'A';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << names[i] << " ";
    }

    return 0;
}