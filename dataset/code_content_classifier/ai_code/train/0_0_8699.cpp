#include<iostream>
using namespace std;
int main(){
    int k, n, w;
    cin >> k >> n >> w;
    int totalCost = 0;
    for(int i=1; i<=w; i++){
        totalCost += i*k;
    }
    int borrow = max(0, totalCost - n);
    cout << borrow << endl;
    return 0;
}