#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> profits(n);
    for(int i = 0; i < n; i++) {
        std::cin >> profits[i];
    }

    std::vector<int> folders;
    int currentFolderLength = 0;
    for(int i = 0; i < n; i++) {
        if(profits[i] < 0) {
            currentFolderLength++;
        } else {
            if(currentFolderLength >= 3) {
                folders.push_back(currentFolderLength);
                currentFolderLength = 0;
            }
        }
    }

    if(currentFolderLength > 0) {
        folders.push_back(currentFolderLength);
    }

    if(folders.empty()) {
        std::cout << "1\n" << n << std::endl;
    } else {
        std::cout << folders.size() << std::endl;
        for(int folderLength : folders) {
            std::cout << folderLength << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}