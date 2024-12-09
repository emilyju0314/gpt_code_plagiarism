#include <iostream>
#include <string>

int main() {
    int n;
    std::string bumpers;
    std::cin >> n;
    std::cin >> bumpers;

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(bumpers[i] == '<' && i == 0) {
            count++;
        } else if(bumpers[i] == '>' && i == n-1) {
            count++;
        } else if(bumpers[i] == '<' && bumpers[i-1] == '>') {
            count++;
        } else if(bumpers[i] == '>' && bumpers[i+1] == '<') {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}