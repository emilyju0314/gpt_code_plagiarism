#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int nf, ne, ns;
    std::cin >> nf >> ne >> ns;
    
    int rf, re, rs;
    std::cin >> rf >> re >> rs;
    
    int df, de;
    std::cin >> df >> de;
    
    double max_damage = 0;
    
    for(int i = 0; i <= nf; i++) {
        for(int j = 0; j <= ne; j++) {
            for(int k = 0; k <= ns; k++) {
                double combined_damage = (df * (nf - i) + de * (ne - j)) * (k + 1);
                max_damage = std::max(max_damage, combined_damage);
            }
        }
    }
    
    double distance = std::numeric_limits<double>::infinity();
    
    if(ns > 0) {
        distance = rs;
    } else if(nf > 0 || ne > 0) {
        distance = std::min(rf, re);
    }
    
    double time = distance / (k + 1);
    
    double final_damage = max_damage * time;
    
    std::cout << std::fixed << std::setprecision(9) << final_damage << std::endl;
    
    return 0;
}