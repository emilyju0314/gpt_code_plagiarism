#include <iostream>
#include <string>

int main() {
    std::string AI_name, phone_name;
    std::cin >> AI_name >> phone_name;

    int replace_count = 0;
    int phone_name_length = phone_name.length();

    for (int i = 0; i <= AI_name.length() - phone_name_length; i++) {
        bool found = true;
        for (int j = 0; j < phone_name_length; j++) {
            if (AI_name[i + j] != phone_name[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            replace_count++;
            i += phone_name_length - 1;
        }
    }

    std::cout << replace_count << std::endl;

    return 0;
}