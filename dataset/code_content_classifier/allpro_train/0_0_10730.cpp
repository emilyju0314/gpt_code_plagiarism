#include <iostream>

using namespace std;

int main() {
    int m, n;
    
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }
        
        int year = m + 1;
        long long total_years = m;
        
        while (total_years % n != 0) {
            total_years += year;
            year++;
        }
        
        cout << total_years << endl;
    }
    
    return 0;
}