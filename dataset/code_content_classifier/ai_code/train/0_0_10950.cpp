#include<iostream>
using namespace std;

int countGoodIntegers(int n) {
    int count = 0;
    for(int i=0; i<=99; i++) {
        int ones = i%10;
        int tens = i/10;
        int brokenSticks = 0;
        if(ones == 0 || ones == 6 || ones == 9) brokenSticks++;
        if(ones == 8) brokenSticks += 2;
        if(tens == 0 || tens == 6 || tens == 9) brokenSticks++;
        if(tens == 8) brokenSticks += 2;
        
        if(n == i + brokenSticks) count++;
    }
    return count;
}

int main() {
    string num;
    cin >> num;
    int n = (num[0]-'0')*10 + (num[1]-'0');
    
    cout << countGoodIntegers(n) << endl;
    
    return 0;
}