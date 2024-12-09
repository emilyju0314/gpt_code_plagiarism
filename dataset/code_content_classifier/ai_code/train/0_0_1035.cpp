#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    int caseNum = 1;
    
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        long long minDeadSpace = LLONG_MAX;
        long long bestA = 0, bestB = 0;
        
        for (long long a = 1; a <= 10000; a++) {
            long long b = ceil(sqrt(a * a / n));
            long long deadSpace = (a * a - n * b * b) / 2;
            
            if (deadSpace < minDeadSpace) {
                minDeadSpace = deadSpace;
                bestA = a;
                bestB = b;
            }
        }
        
        cout << "Case " << caseNum << ": " << bestA << " " << bestB << endl;
        caseNum++;
    }
    
    return 0;
}