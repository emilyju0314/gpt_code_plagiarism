#include <iostream>
#include <unordered_map>

int main() {
    // Create a map to store the mappings of document identifier to subject
    std::unordered_map<int, int> documentMapping;

    // Add mappings for documents in directories 1, 2, and 3
    for (int i = 0; i < 3; ++i) {
        int subject;
        std::cin >> subject;

        int numDocs;
        std::cin >> numDocs;

        for (int j = 0; j < numDocs; ++j) {
            int id;
            std::cin >> id;
            documentMapping[id] = subject;
        }
    }

    // Read the input document identifier
    int docId;
    std::cin >> docId;

    // Output the subject of the given document
    std::cout << documentMapping[docId] << std::endl;

    return 0;
}