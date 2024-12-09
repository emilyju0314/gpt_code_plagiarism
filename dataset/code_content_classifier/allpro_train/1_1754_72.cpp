#include <iostream>
#include <algorithm>
using namespace std;

#define nl "\n"
#define ii >>
#define oo <<

int main(){
    int q,i,n,x,j,k;
    cin ii q;
    for(i=0;i<q;i++){
        cin ii n ii x;
        int arr[n];
        //scanned array
        for(j=0;j<n;j++){
            cin ii arr[j];
        }
        //check for sorted
        if(is_sorted(arr,arr+n)){
            cout oo "0" oo nl; 
        }else{
            int numberoftimes=0,swapper,tmpswapper;
            swapper = x;
            for(k=0;k<n;k++){
                //Swap
                if(arr[k]>swapper){
                    tmpswapper = swapper;
                    swapper = arr[k];
                    arr[k] = tmpswapper;
                    numberoftimes = numberoftimes + 1;
                }
                //Check for sorted
                if(is_sorted(arr,arr+n)){
                    cout oo numberoftimes oo nl;
                    break;
                }
            }
            if(is_sorted(arr,arr+n)){
                
            }else{
                cout oo "-1" oo nl;
            }
        }
    }
    return 0;
}