#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string sequence1, sequence2;
    std::cin >> sequence1 >> sequence2;

    std::string result = "";
    int index1 = 0, index2 = 0;

    while (index1 < sequence1.length() && index2 < sequence2.length()) {
        if (sequence1[index1] == sequence2[index2]) {
            result += sequence1[index1];
            index1++;
            index2++;
        } else {
            result += "0";
            index1++;
            index2++;
        }
    }

    // If there are remaining characters in sequence1
    while (index1 < sequence1.length()) {
        result += sequence1[index1];
        index1++;
    }

    // If there are remaining characters in sequence2
    while (index2 < sequence2.length()) {
        result += sequence2[index2];
        index2++;
    }

    std::cout << result << std::endl;

    return 0;
}