#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grades(n);
    for(int i = 0; i < n; i++) {
        cin >> grades[i];
    }
    
    int successfulStudents = 0;
    
    for(int i = 0; i < n; i++) {
        bool successful = false;
        for(int j = 0; j < m; j++) {
            bool bestAtSubject = true;
            for(int k = 0; k < n; k++) {
                if(grades[k][j] > grades[i][j]) {
                    bestAtSubject = false;
                    break;
                }
            }
            if(bestAtSubject) {
                successful = true;
                break;
            }
        }
        if(successful) {
            successfulStudents++;
        }
    }
    
    cout << successfulStudents << endl;
    
    return 0;
}