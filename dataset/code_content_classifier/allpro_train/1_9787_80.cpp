#include<iostream>
 
using namespace std;
 
int main(){
    int a,b,c;
    int i;
    cin >> a >> b >> c;
    i=0;
    while(i<60){
        if((c+60*i)%(a+b)<=a){
            cout << (i*60+c) << '\n';
            break;
        }
        i++;
    }
    if(i==60){
        cout <<-1<< '\n';
    }
}