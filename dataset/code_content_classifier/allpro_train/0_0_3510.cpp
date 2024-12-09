#include <iostream>

int main() {
    int a;
    std::cin >> a;

    // Initial cell values
    char cells[30000] = {0};
    int cell_pointer = 0;

    // Code snippet to convert A to the corresponding value
    // Uses cell values 4,8,15,16,23,42 as placeholders
    int A = 4 + 8 + 15 + 16 + 23;

    // Loop through the given code snippet
    for (int i = 0; i < 490; i++) {
        switch(cells[cell_pointer]) {
            case '>':
                cell_pointer++;
                break;
            case '<':
                cell_pointer--;
                break;
            case '+':
                cells[cell_pointer]++;
                break;
            case '-':
                cells[cell_pointer]--;
                break;
            case '.':
                std::cout << (int)cells[cell_pointer] << std::endl;
                break;
        }
    }

    int result = (int)cells[0];
    std::cout << result;

    return 0;
}