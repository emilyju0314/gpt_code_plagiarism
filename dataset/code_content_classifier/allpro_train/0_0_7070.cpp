#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    int asciiCode = input[0]; // get the ASCII code of the character

    // Output the program in the described language
    std::cout << ".......X.......\n";
    std::cout << "......XXX......\n";
    std::cout << ".....XXXXX.....\n";
    std::cout << "....XXXXXXX....\n";
    std::cout << "...XXXXXXXXX...\n";
    std::cout << "..XXXXXXXXXXX..\n";
    std::cout << ".XXXXXXXXXXXXX.\n";
    std::cout << "...............\n";
    std::cout << "X.............X\n";
    std::cout << "X..............\n";
    std::cout << "X..............\n";
    std::cout << "X..............\n";

    // Output the Brainfuck program
    std::cout << "      -\n";
    std::cout << "     >+<\n";
    std::cout << "    >+++<\n";
    std::cout << "   >+++++<\n";
    std::cout << "  >+++++++<\n";
    std::cout << " >+++++++++<\n";
    std::cout << ">+++++++++++<\n";
    std::cout << "\n";
    std::cout << "<             >\n";
    std::cout << ".\n";
    std::cout << ".\n";
    std::cout << ".\n";

    return 0;
}