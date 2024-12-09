#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int ans[N]={0};
    
    for(int x=1; x<=100; x++){
        for(int y=1; y<=100; y++){
            for(int z=1; z<=100; z++){
                int total = x*x + y*y + z*z + x*y + y*z + z*x;
                if(total <= N){
                    ans[total-1]++;
                }
            }
        }
    }
    
    for(int i=0; i<N; i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}