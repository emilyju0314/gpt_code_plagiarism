#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    // Initialize the upper and lower parts of the blackboard
    std::string upper(N, '#');
    std::string lower(N, '#');

    // Keep track of the number of search queries
    int queries = 0;

    // Loop to output search queries
    while (true) {
        // Print search query
        std::cout << upper << std::endl;
        std::cout << lower << std::endl;

        // Receive the search result
        char result;
        std::cin >> result;

        // Check if the whole blackboard is found or limit exceeded
        if (result == 'T' || queries >= 100) {
            std::cout << "end" << std::endl;
            break;
        }

        // Update the upper and lower parts of the blackboard
        for (int i = 0; i < N; ++i) {
            if (upper[i] == '#') {
                upper[i] = '.';
                lower[i] = '#';
                break;
            }
        }

        // Increment the number of search queries
        queries++;
    }

    return 0;
}