#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> records;
    for (int i = 0; i < N; i++) {
        std::string record;
        std::cin >> record;
        records.push_back(record);
    }

    bool replied = false;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (records[i] == "A") {
            replied = false;
        } else {
            if (!replied) {
                replied = true;
                count++;
            } else {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }

    if (count == N / 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}