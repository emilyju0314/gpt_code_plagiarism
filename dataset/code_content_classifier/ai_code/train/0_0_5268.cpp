#include <iostream>

int main() {
    int n;
    
    while(std::cin >> n && n != 0) {
        int max_distance = 0, patient_number = 0;
        
        for(int i = 0; i < n; i++) {
            int p, d1, d2;
            std::cin >> p >> d1 >> d2;
            
            if (d1 + d2 > max_distance) {
                max_distance = d1 + d2;
                patient_number = p;
            }
        }
        
        std::cout << patient_number << " " << max_distance << std::endl;
    }
    
    return 0;
}