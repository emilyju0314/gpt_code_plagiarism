#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    int minN = n;
    int minOps = 0;
    
    int x = 2;
    while(x*x <= n) {
        int tempN = n;
        int tempOps = 0;
        
        while(tempN % x == 0) {
            tempN /= x;
            tempOps++;
        }
        
        if(tempN == 1 && tempOps < minOps) {
            minN = n;
            minOps = tempOps;
        }
        
        x++;
    }
    
    if(minOps == 0) {
        minN = 1;
        minOps = 0;
    }
    
    std::cout << minN << " " << minOps << std::endl;
    
    return 0;
}