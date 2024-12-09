#include<iostream>
#include<string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int verticalCount = 0;
    
    int lastR = -1;
    int lastL = -1;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            verticalCount += (i - lastR - 1);
            lastR = i;
        } 
        else if(s[i] == 'L') {
            if(lastR == -1) {
                verticalCount += (i - lastL - 1);
            } 
            else {
                verticalCount += (i - lastL - 1) / 2;
            }
            lastL = i;
        }
    }

    if(lastR == -1) {
        verticalCount += (n - lastL - 1);
    } 
    else {
        verticalCount += (n - lastL - 1) / 2;
    }

    cout << verticalCount << endl;

    return 0;
}