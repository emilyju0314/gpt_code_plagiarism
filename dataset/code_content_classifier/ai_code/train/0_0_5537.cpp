#include <iostream>
#include <string>

int pasteOperations(const std::string& tree, int& index) {
    if (tree[index] == '(') {
        index++; // skip opening parenthesis
        int left = pasteOperations(tree, index);
        int right = pasteOperations(tree, index);
        index++; // skip closing parenthesis
        return std::min(left, right) + 1;
    } else {
        return 0;
    }
}

int main() {
    std::string tree;
    std::cin >> tree;

    int index = 0;
    int operations = pasteOperations(tree, index);

    std::cout << operations << std::endl;

    return 0;
}