#include <iostream>
#include <string>

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    char acronym[3];
    acronym[0] = toupper(s1[0]);
    acronym[1] = toupper(s2[0]);
    acronym[2] = toupper(s3[0]);

    std::cout << acronym << std::endl;

    return 0;
}