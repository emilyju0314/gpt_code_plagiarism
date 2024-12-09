#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
    int id;
    std::string name, temp;
    std::unordered_map<std::string, int> subjects; // Map to store subject based on document name

    // Read input
    std::cin >> id;
    std::cin >> name;

    // Read and store training set documents
    for (int i = 1; i <= 3; ++i) {
        std::ifstream file("train/" + std::to_string(i) + "/" + std::to_string(i) + ".txt");
        while (std::getline(file, temp)) {
            if (temp == name) {
                subjects[name] = i;
            }
        }
        file.close();
    }

    // Output the subject corresponding to the given document
    std::cout << subjects[name] << std::endl;

    return 0;
}