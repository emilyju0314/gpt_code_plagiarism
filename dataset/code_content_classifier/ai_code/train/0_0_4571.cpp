#include<iostream>
using namespace std;

int main(){
    long long N, A;
    cin >> N >> A;

    long long cookies = 0;
    long long time = 0;

    while(cookies < N){
        time++;
        if(cookies >= A){
            cookies = cookies - A;
        } else {
            cookies++;
        }
    }

    cout << time << endl;

    return 0;
}