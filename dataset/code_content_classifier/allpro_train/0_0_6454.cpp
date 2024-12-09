#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string types;
    std::cin >> types;

    std::unordered_map<char, int> typeCount;
    int uniqueTypes = 0;
    int minLength = n;

    for (int i = 0; i < n; i++) {
        if (typeCount[types[i]] == 0) {
            uniqueTypes++;
        }
        typeCount[types[i]]++;

        if (uniqueTypes == 26) {
            while (typeCount[types[i - minLength + 1]] > 1) {
                typeCount[types[i - minLength + 1]]--;
                minLength--;
            }
        }
    }

    std::cout << minLength << std::endl;

    return 0;
}