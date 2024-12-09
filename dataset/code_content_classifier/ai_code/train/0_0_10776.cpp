#include<iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    int count = 0;
    while(n > 0){
        if(n % 10 == 1){
            count++;
        }
        n /= 10;
    }
    
    cout << count << endl;
    
    return 0;
}