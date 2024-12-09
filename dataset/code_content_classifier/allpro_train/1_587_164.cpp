#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void){
	while(1){
        int a[10]={0};
        int n;
        int b;
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>b;
            if(b<=9)a[0]++;
            else if(b<=19)a[1]++;
            else if(b<=29)a[2]++;
            else if(b<=39)a[3]++;
            else if(b<=49)a[4]++;
            else if(b<=59)a[5]++;
            else a[6]++;
        }
        for(int i=0;i<7;i++){
            cout<<a[i]<<endl;

        }

	}
	return 0;
}