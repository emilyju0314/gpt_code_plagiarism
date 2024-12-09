#include <iostream>
#include <iomanip>

int main() {
    int T, H, S;
    
    while(std::cin >> T >> H >> S) {
        if(T == -1 && H == -1 && S == -1) {
            break;
        }
        
        int totalSeconds = T * 60 * 60 + H * 60 + S;
        int remainingSeconds = 120 * 60 - totalSeconds;
        
        int remainingHoursStandard = remainingSeconds / 3600;
        int remainingMinutesStandard = (remainingSeconds % 3600) / 60;
        int remainingSecondsStandard = remainingSeconds % 60;
        
        int remainingHoursTriple = 3 * remainingHoursStandard;
        int remainingMinutesTriple = 3 * remainingMinutesStandard;
        int remainingSecondsTriple = 3 * remainingSecondsStandard;
        
        std::cout << std::setfill('0') << std::setw(2) << remainingHoursStandard << ":";
        std::cout << std::setfill('0') << std::setw(2) << remainingMinutesStandard << ":";
        std::cout << std::setfill('0') << std::setw(2) << remainingSecondsStandard << std::endl;
        
        std::cout << std::setfill('0') << std::setw(2) << remainingHoursTriple << ":";
        std::cout << std::setfill('0') << std::setw(2) << remainingMinutesTriple << ":";
        std::cout << std::setfill('0') << std::setw(2) << remainingSecondsTriple << std::endl;
    }
    
    return 0;
}