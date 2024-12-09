#include<iostream>
using namespace std;

int main(){
    int a,b;
    char op;
    while(cin >> a >> op >> b,op != '?'){
        cout << (op=='+'?a+b : op=='-'?a-b : op=='*'?a*b : a/b) << endl;
    }
    return 0;
}
