#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;

    std::unordered_set<int> errors;
    for(int i = 0; i < n; i++) {
        int error;
        std::cin >> error;
        errors.insert(error);
    }

    std::unordered_set<int> removedErrors;
    for(int i = 0; i < n - 1; i++) {
        int error;
        std::cin >> error;
        if(errors.find(error) != errors.end()) {
            errors.erase(error);
        } else {
            removedErrors.insert(error);
        }
    }

    for(int i = 0; i < n - 2; i++) {
        int error;
        std::cin >> error;
        if(errors.find(error) != errors.end()) {
            errors.erase(error);
        } else {
            removedErrors.insert(error);
        }
    }

    for(auto error : errors) {
        std::cout << error << " ";
    }

    std::cout << std::endl;

    for(auto error : removedErrors) {
        std::cout << error << " ";
    }

    return 0;
}