#include <iostream>
#include <vector>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, std::set<std::string>> phonebook;

    for (int i = 0; i < n; ++i) {
        std::string name;
        int count;
        std::cin >> name >> count;

        for (int j = 0; j < count; ++j) {
            std::string number;
            std::cin >> number;

            bool has_suffix = false;
            for (const auto& [friend_name, numbers] : phonebook) {
                for (const std::string& suffix : numbers) {
                    if (number.size() < suffix.size() && suffix.substr(suffix.size() - number.size()) == number) {
                        has_suffix = true;
                        break;
                    }
                }
            }

            if (!has_suffix) {
                phonebook[name].insert(number);
            }
        }
    }

    std::cout << phonebook.size() << std::endl;

    for (const auto& [name, numbers] : phonebook) {
        std::cout << name << " " << numbers.size();
        for (const std::string& number : numbers) {
            std::cout << " " << number;
        }
        std::cout << std::endl;
    }

    return 0;
}