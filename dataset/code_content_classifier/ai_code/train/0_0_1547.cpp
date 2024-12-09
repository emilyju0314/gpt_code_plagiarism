#include<iostream>
using namespace std;

int main() {
    int candies;
    
    while(cin >> candies) {
        int last_student = candies % 39;
        if(last_student == 0) {
            last_student = 39;
        }
        
        if(last_student < 10) {
            cout << "3C0" << last_student << endl;
        } else {
            cout << "3C" << last_student << endl;
        }
    }
    
    return 0;
}