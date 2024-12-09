#include<iostream>
#include<string>

using namespace std;

int main() {
    int b, d;
    string a, c;
    
    cin >> b >> d;
    cin >> a >> c;
    
    int p = 0;
    for(int i = 1; i <= b*d; i++) {
        string temp = c;
        for(int j = 1; j < d; j++) {
            temp += c;
        }
        if(a.find(temp) != string::npos) {
            p = i;
        }
        c += c;
    }
    
    cout << p << endl;
    
    return 0;
}