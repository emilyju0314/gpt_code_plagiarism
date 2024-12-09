#include <iostream>

int main() {
    int P;
    std::cin >> P;
    
    int total_amount = 0;
    int special_chat[] = {10000, 5000, 1000, 500};

    for(int i=0; i<4; i++) {
        while(P >= special_chat[i]) {
            total_amount += special_chat[i];
            P -= special_chat[i];
        }
    }

    std::cout << total_amount << std::endl;

    return 0;
}