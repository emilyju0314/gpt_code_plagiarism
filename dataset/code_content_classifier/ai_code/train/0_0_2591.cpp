#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, nmin, nmax;
    
    while (true) {
        cin >> m >> nmin >> nmax;
        
        if (m == 0 && nmin == 0 && nmax == 0) {
            break;
        }
        
        vector<int> scores(m);
        for (int i = 0; i < m; i++) {
            cin >> scores[i];
        }
        
        int max_gap = 0;
        int successful_applicants = nmin;
        
        for (int n = nmin; n <= nmax; n++) {
            int gap = scores[n-1] - scores[n];
            if (gap > max_gap) {
                max_gap = gap;
                successful_applicants = n;
            }
        }
        
        cout << successful_applicants << endl;
    }
    
    return 0;
}