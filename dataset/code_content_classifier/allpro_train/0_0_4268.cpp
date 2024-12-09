#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    int swaps = 0;
    int replacements = 0;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            if (a[i] == '7' && b[i] == '4') {
                replacements++;
            } else if (a[i] == '4' && b[i] == '7') {
                replacements++;
            } else {
                swaps++;
            }
        }
    }

    int total_operations = std::max(swaps, replacements);

    std::cout << total_operations << std::endl;

    return 0;
}