#include <iostream>
#include <string>

std::string generateLogin(std::string firstName, std::string lastName) {
    std::string login;
    
    if (firstName < lastName) {
        login = firstName[0] + lastName.substr(0, 1);
    } else {
        login = lastName[0] + firstName.substr(0, 1);
    }
    
    return login;
}

int main() {
    std::string firstName, lastName;
    std::cin >> firstName >> lastName;
    
    std::string login = generateLogin(firstName, lastName);
    
    std::cout << login << std::endl;
    
    return 0;
}