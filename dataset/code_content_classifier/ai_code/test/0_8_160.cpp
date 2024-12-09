#include <iostream>
#include <cmath>

int findTimeToClean(int n, int m, int rb, int cb, int rd, int cd) {
    int dr = 1, dc = 1;
    int time = 0;
    
    while(rb != rd || cb != cd) {
        if(rb != rd && cb != cd) {
            if(dr == 1)
                dr = rd > rb ? 1 : -1;
            if(dc == 1)
                dc = cd > cb ? 1 : -1;
        }
        else if(rb != rd) {
            dr = rd > rb ? 1 : -1;
            dc = 0;
        }
        else if(cb != cd) {
            dr = 0;
            dc = cd > cb ? 1 : -1;
        }
        
        rb += dr;
        cb += dc;
        time++;
    }
    
    return time;
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, m, rb, cb, rd, cd;
        std::cin >> n >> m >> rb >> cb >> rd >> cd;
        
        int time = findTimeToClean(n, m, rb, cb, rd, cd);
        std::cout << time << std::endl;
    }
    
    return 0;
}