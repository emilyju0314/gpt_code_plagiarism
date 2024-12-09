#include <iostream>

using namespace std;
long long a[50],k;
int main(){
    cin >> k;
    long long i,x = k%50;
    cout << 50 << endl;
    for(i=0;i<50;i++){
        a[i] = 50 - i;
    }
    for(i=0;i<50;i++){
        if(i<x) a[i] += k/50;
        else a[i] += (k/50-1LL);
        cout << a[i] << " ";
    }
    cout << endl;
}