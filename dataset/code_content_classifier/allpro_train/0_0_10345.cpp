#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string masha_number;
    std::cin >> masha_number;

    int total_numbers = 0;

    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == i) continue;

            int first_digit = i;
            int second_digit = round((masha_number[0] - '0' + first_digit) / 2);
            
            for(int k = 0; k <= 9; k++) {
                if(k == j) continue;
                
                int third_digit = round((masha_number[1] - '0' + second_digit) / 2);
                
                for(int l = 0; l <= 9; l++) {
                    if(l == k) continue;
                    
                    int fourth_digit = round((masha_number[2] - '0' + third_digit) / 2);
                    
                    for(int m = 0; m <= 9; m++) {
                        if(m == l) continue;
                        
                        int fifth_digit = round((masha_number[3] - '0' + fourth_digit) / 2);
                        
                        total_numbers++;
                    }
                }
            }
        }
    }

    std::cout << total_numbers << std::endl;

    return 0;
}