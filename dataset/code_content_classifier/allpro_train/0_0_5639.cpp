#include <iostream>
#include <string>

int countEvenSubstrings(std::string a, std::string b) {
    int b_length = b.length();
    int even_count = 0;

    for (int i = 0; i <= a.length() - b_length; i++) {
        int diff_count = 0;
        for (int j = 0; j < b_length; j++) {
            if (a[i + j] != b[j]) {
                diff_count++;
            }
        }
        if (diff_count % 2 == 0) {
            even_count++;
        }
    }

    return even_count;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    int answer = countEvenSubstrings(a, b);
    std::cout << answer << std::endl;

    return 0;
}